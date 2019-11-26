/*
This directory is system relative 
*/

var addon = require('cuda-node-js');



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
//the 3rd argument is Ambiguous
console.log(addon.math_func(3,2,5));
console.log(addon.math_func(4,5,6));

