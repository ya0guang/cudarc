// #define __CUDA_INCLUDE_COMPILER_INTERNAL_HEADERS__
// #define __CUDA_INTERNAL_COMPILATION__
// #define size_t unsigned long
#include "cuda_runtime.h"
#include "cuda_runtime_api.h"
#include "cuda_profiler_api.h"

// This struct is from fatbinary_section.h

typedef struct
{
  int magic;
  int version;
  const unsigned long long *data;
  void *filename_or_fatbins; /* version 1: offline filename,
                              * version 2: array of prelinked fatbins */
} __fatBinC_Wrapper_t;

/*
 * These defines are for the fatbin.c runtime wrapper
 */
#define FATBINC_MAGIC 0x466243B1
#define FATBINC_VERSION 1
#define FATBINC_LINK_VERSION 2

// Functions in crt/cuda_runtime.h
// These lines are copied from cuda_runtime.h, with `CUDARTAPI` removed

extern void **__cudaRegisterFatBinary(
    __fatBinC_Wrapper_t *fatCubin);

extern void __cudaRegisterFatBinaryEnd(
    void **fatCubinHandle);

extern void __cudaUnregisterFatBinary(
    void **fatCubinHandle);

extern void __cudaRegisterVar(
    void **fatCubinHandle,
    char *hostVar,
    char *deviceAddress,
    const char *deviceName,
    int ext,
    size_t size,
    int constant,
    int global);

extern void __cudaRegisterManagedVar(
    void **fatCubinHandle,
    void **hostVarPtrAddress,
    char *deviceAddress,
    const char *deviceName,
    int ext,
    size_t size,
    int constant,
    int global);

extern char __cudaInitModule(
    void **fatCubinHandle);

extern void __cudaRegisterTexture(
    void **fatCubinHandle,
    const struct textureReference *hostVar,
    const void **deviceAddress,
    const char *deviceName,
    int dim,
    int norm,
    int ext);

extern void __cudaRegisterSurface(
    void **fatCubinHandle,
    const struct surfaceReference *hostVar,
    const void **deviceAddress,
    const char *deviceName,
    int dim,
    int ext);

extern void __cudaRegisterFunction(
    void **fatCubinHandle,
    const char *hostFun,
    char *deviceFun,
    const char *deviceName,
    int thread_limit,
    uint3 *tid,
    uint3 *bid,
    dim3 *bDim,
    dim3 *gDim,
    int *wSize);

extern cudaError_t __cudaPopCallConfiguration(
    dim3 *gridDim,
    dim3 *blockDim,
    size_t *sharedMem,
    void *stream);

// functions in crt/device_runtime.h

extern unsigned __cudaPushCallConfiguration(dim3 gridDim,
                                            dim3 blockDim,
                                            size_t sharedMem,
                                            struct CUstream_st *stream);
