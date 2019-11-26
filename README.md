# Node JS Cuda binding
node-js-cuda

## Prerequisites :

* **nvcc** must be installed. Check it using **nvcc —version**
*  g++/cc to be installed.
*  npm and node version 10.x +
* **nan** is needed which can be installed by npm.

## Working Example  :
Here is the google Colab link 
The test.cu you can get it this GitHub repo. in real time you can use your own **.cu** program .

##Google colab link:
https://colab.research.google.com/drive/1ZQr696mvpMnHyImohrwwefxpgiNCAC-w

## Compile from the source and test:

```
!git clone https://github.com/generic-matrix/node-js-cuda.git
!cd node-js-cuda && npm install --unsafe-perm -g
!cd node-js-cuda && node index.js
   ```

## Make sure to make it run we need to update the following as it may be machine specific :

 ```"sources": [ "main.cpp",'/content/node-js-cuda/test.o'],```
 
 ## And
 ```'library_dirs': [ '/usr/local/cuda/lib64']```
 in the **binding.gyp**



## What’s next ?
**We will need to implement shared memory** between nan and **.cu** so the GPUs access will become faster 
