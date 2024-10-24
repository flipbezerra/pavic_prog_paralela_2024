// Teste de uso da biblioteca CUDA

#include <stdio.h>
#include <iostream>
#include "cuda_runtime.h"
#include "device_launch_parameters.h"


// kERNEL TO RUN INTO DEVICE (GPU !!) !!
__global__ void add(int* a, int* b, int* c) {
    *c = *a + *b;
}

int main(int argc, char** argv) {
    int a, b, c;                // host copies of a, b, c
    int* d_a, * d_b, * d_c;        // device copies of a, b, c
    int size = sizeof(int);

    // STEP 1. Allocate memory space in device(GPU) for data
    // Allocate space for device copies of a, b, c
    cudaMalloc((void**)&d_a, size);
    cudaMalloc((void**)&d_b, size);
    cudaMalloc((void**)&d_c, size);

   
    // STEP 2.  Allocate memory space in host(CPU) for data

    // Setup input values
    a = 2; //-->>d_a
    b = 7; // -->>d_b

    // STEP 3.  Copy data to GPU
    // Copy inputs to device
    // cudaMemcpy(Destination, Source, size, Directions);
    cudaMemcpy(d_a, &a, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, &b, size, cudaMemcpyHostToDevice);

    // STEP 4.  Call “kernel” routine to execute on GPU(with CUDA syntax that defines no of threads and their physical structure)
    // Launch add() kernel on GPU
    add <<<1, 1 >>> (d_a, d_b, d_c);

    // STEP 5.  Transfer results from GPU to CPU
     // Copy result back to host
    // d_c --->>c
    cudaMemcpy(&c, d_c, size, cudaMemcpyDeviceToHost);

    std::cout <<"Result = " << c << std::endl;

    //
    // STEP 6.  Free memory space in device(GPU)
    // Cleanup
    cudaFree(d_a); cudaFree(d_b); cudaFree(d_c);
   
    // STEP 7.  Free memory space in host(CPU)
       
    return 0;
}