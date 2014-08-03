const
    addon = require('./build/Release/addon'),
    add   = addon.add,
    num1  = +process.argv[2] || 2,
    num2  = +process.argv[3] || 2;

console.log(add(num1, num2));
