var addon = require('/content/node-js-cuda/build/Release/addon.node');



/*
The first argument stand for: 
     0 --> Addition
     1 --> Subtract
     2 --> Multiplication
     3 --> Exponential
     4 --> Power
*/

console.log(addon.math_func(0,4,5));
console.log(addon.math_func(1,5,6));
console.log(addon.math_func(2,5,6));
console.log(addon.math_func(3,2,5));
//the 2nd argument is Ambiguous
console.log(addon.math_func(4,5,6));

