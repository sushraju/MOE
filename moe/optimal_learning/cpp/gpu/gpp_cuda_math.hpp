/*!
  \file gpp_cuda_math.hpp
  \rst
  Functions compiled by nvcc are all declared here. 
\endrst*/

#ifndef MOE_OPTIMAL_LEARNING_CPP_GPU_GPP_CUDA_MATH_HPP
#define MOE_OPTIMAL_LEARNING_CPP_GPU_GPP_CUDA_MATH_HPP

#define EI_THREAD_NO 256
#define EI_BLOCK_NO 32
#define GRADEI_THREAD_NO 256
#define GRADEI_BLOCK_NO 32

#include "driver_types.h"

namespace optimal_learning {

struct CudaError{
  cudaError_t err;
  char* file;
  int line;
};

extern "C" CudaError cuda_get_EI(double * __restrict__ mu, double * __restrict__ L, double best, int num_union_of_pts, double * __restrict__ dev_mu, double * __restrict__ dev_L, double * __restrict__ dev_EIs, unsigned int seed, int num_mc, double* __restrict__ ei_val, double* __restrict__ dev_random_number_EI, double* __restrict__ random_number_EI, bool configure_for_test);

extern "C" CudaError cuda_get_gradEI(double * __restrict__ mu, double * __restrict__ grad_mu, double * __restrict__ L, double * __restrict__ grad_L, double best, int num_union_of_pts, int num_to_sample, int dimension, double * __restrict__ dev_mu, double * __restrict__ dev_grad_mu, double * __restrict__ dev_L, double * __restrict__ dev_grad_L, double * __restrict__ dev_grad_EIs, unsigned int seed, int num_mc, double * __restrict__ grad_EI, double* __restrict__
         dev_random_number_gradEI, double* __restrict__ random_number_gradEI, bool configure_for_test);

extern "C" CudaError cuda_allocate_mem_for_double_vector(int num_doubles, double** __restrict__ ptr_to_ptr);

extern "C" void cuda_free_mem(double* __restrict__ ptr);

extern "C" CudaError cuda_set_device(int devID);

}   // end namespace optimal_learning
#endif  // MOE_OPTIMAL_LEARNING_CPP_GPU_GPP_CUDA_MATH_HPP
