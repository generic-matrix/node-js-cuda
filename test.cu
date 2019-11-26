#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
 
 //!!nvcc -c  test.cu --compiler-options -fPIC
 //!g++ -o program -L/usr/local/cuda/lib64 main.cpp test.o -lcuda -lcudart 
 
__global__ void add(float *a,float *b,float *c)
{
         *c = *a +*b;
}  
 
__global__ void sub(float *a,float *b,float *c)
{
         *c = *a -*b;
}  
 
__global__ void exp(float *a,float *c)
{
         *c = expf(*a);
}  
 
__global__ void mul(float *a,float *b,float *c)
{
         *c = *a * *b;
}  
 
__global__ void pow(float *a,float *b,float *c)
{
         *c = powf(*a,*b);
}  
 
 

float vecAdd_wrapper(float a,float b)
{
        float c;
        float*d_a, *d_b, *d_c; 
        int size = sizeof(float);
        
        cudaMallocManaged((void **)&d_a, size);
        cudaMallocManaged((void **)&d_b, size);
        cudaMallocManaged((void **)&d_c, size);

        cudaMemcpy(d_a, &a, size, cudaMemcpyHostToDevice);
        cudaMemcpy(d_b, &b, size, cudaMemcpyHostToDevice);

        add<<<1,1>>>(d_a, d_b, d_c);

        cudaMemcpy(&c, d_c, size, cudaMemcpyDeviceToHost);

        cudaFree(d_a); cudaFree(d_b); cudaFree(d_c);
        
        return c;
}

float vecSub_wrapper(float a,float b)
{
        float c;
        float*d_a, *d_b, *d_c; 
        int size = sizeof(float);
        
        cudaMallocManaged((void **)&d_a, size);
        cudaMallocManaged((void **)&d_b, size);
        cudaMallocManaged((void **)&d_c, size);

        cudaMemcpy(d_a, &a, size, cudaMemcpyHostToDevice);
        cudaMemcpy(d_b, &b, size, cudaMemcpyHostToDevice);

        sub<<<1,1>>>(d_a, d_b, d_c);

        cudaMemcpy(&c, d_c, size, cudaMemcpyDeviceToHost);

        cudaFree(d_a); cudaFree(d_b); cudaFree(d_c);
        
        return c;
}

float vecMul_wrapper(float a,float b)
{
        float c;
        float*d_a, *d_b, *d_c; 
        int size = sizeof(float);
        
        cudaMallocManaged((void **)&d_a, size);
        cudaMallocManaged((void **)&d_b, size);
        cudaMallocManaged((void **)&d_c, size);

        cudaMemcpy(d_a, &a, size, cudaMemcpyHostToDevice);
        cudaMemcpy(d_b, &b, size, cudaMemcpyHostToDevice);

        mul<<<1,1>>>(d_a, d_b, d_c);

        cudaMemcpy(&c, d_c, size, cudaMemcpyDeviceToHost);

        cudaFree(d_a); cudaFree(d_b); cudaFree(d_c);
        
        return c;
}

float vecExp_wrapper(float a)
{
        float c;
        float*d_a,*d_c; 
        int size = sizeof(float);
        
        cudaMallocManaged((void **)&d_a, size);
        cudaMallocManaged((void **)&d_c, size);

        cudaMemcpy(d_a, &a, size, cudaMemcpyHostToDevice);

        exp<<<1,1>>>(d_a, d_c);

        cudaMemcpy(&c, d_c, size, cudaMemcpyDeviceToHost);

        cudaFree(d_a); cudaFree(d_c);
        
        return c;
}


float vecPow_wrapper(float a,float b)
{
        float c;
        float*d_a, *d_b, *d_c; 
        int size = sizeof(float);
        
        cudaMallocManaged((void **)&d_a, size);
        cudaMallocManaged((void **)&d_b, size);
        cudaMallocManaged((void **)&d_c, size);

        cudaMemcpy(d_a, &a, size, cudaMemcpyHostToDevice);
        cudaMemcpy(d_b, &b, size, cudaMemcpyHostToDevice);

        pow<<<1,1>>>(d_a, d_b, d_c);

        cudaMemcpy(&c, d_c, size, cudaMemcpyDeviceToHost);

        cudaFree(d_a); cudaFree(d_b); cudaFree(d_c);
        
        return c;
}