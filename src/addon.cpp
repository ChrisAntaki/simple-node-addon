#define BUILDING_NODE_EXTENSION
#include <node.h>

using namespace v8;

Handle<Value> Add(const Arguments& args) {
    HandleScope scope;

    if (args.Length() != 2) {
        ThrowException(
            Exception::TypeError(
                String::New("Expected two arguments")
            )
        );
        return scope.Close(Undefined());
    }

    if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
        ThrowException(
            Exception::TypeError(
                String::New("Expected two numbers")
            )
        );
        return scope.Close(Undefined());
    }

    const Local<Number> result = Number::New(
        args[0]->NumberValue() + args[1]->NumberValue()
    );

    return scope.Close(result);
}

Handle<Value> Concat(const Arguments& args) {
    HandleScope scope;

    if (args.Length() != 2) {
        ThrowException(
            Exception::TypeError(
                String::New("Expected two arguments")
            )
        );
        return scope.Close(Undefined());
    }

    if (!args[0]->IsString() || !args[1]->IsString()) {
        ThrowException(
            Exception::TypeError(
                String::New("Expected two strings")
            )
        );
        return scope.Close(Undefined());
    }

    const Local<String> result = String::Concat(
        args[0]->ToString(), args[1]->ToString()
    );

    return scope.Close(result);
}

void Init(Handle<Object> exports, Handle<Object> module) {
    exports->Set(
        String::NewSymbol("add"),
        FunctionTemplate::New(Add)->GetFunction()
    );

    exports->Set(
        String::NewSymbol("concat"),
        FunctionTemplate::New(Concat)->GetFunction()
    );
}

NODE_MODULE(addon, Init)
