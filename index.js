var addon = require('/content/node-js-cuda/build/Release/addon.node');



     console.log(addon.math_func("add",4,5));
     console.log(addon.math_func("sub",5,6));
     console.log(addon.math_func("mul",5,6));
     console.log(addon.math_func("exp",2,5));
     console.log(addon.math_func("pow",5,6));

