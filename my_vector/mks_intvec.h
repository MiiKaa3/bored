#ifndef MKS_INTVEC_H
#define MKS_INTVEC_H

#include <stdlib.h>
#define MKS_VEC_T   int

typedef struct MKS_INT_VEC
{
  size_t len;
  size_t upper;
  MKS_VEC_T* data;
} mks_intVec;

mks_intVec* mks_intVecInit();
mks_intVec* mks_intVecInitReserve(size_t numElems);
void mks_intVecFree(mks_intVec* in);
void mks_intVecReserve(mks_intVec* in, size_t newUpper);
void mks_intVecRealloc(mks_intVec* in);
void mks_intVecSetVal(mks_intVec* in, MKS_VEC_T value, size_t index);
MKS_VEC_T mks_intVecGetVal(mks_intVec* in, size_t index);

#endif