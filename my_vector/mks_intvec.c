#include "mks_intvec.h"
#include <stdio.h>
#include <errno.h>
#define raise(error_code, msg)   { errno = error_code; perror(msg); exit(EXIT_FAILURE); }

mks_intVec* mks_intVecInit()
{
  mks_intVec* res = (mks_intVec*)malloc(sizeof(mks_intVec));
  res->len = 0;
  res->upper = 10;
  res->data = (MKS_VEC_T*)malloc(res->upper * sizeof(MKS_VEC_T));
  return res; 
}

mks_intVec* mks_intVecInitReserve(size_t numElems)
{
  mks_intVec* res = (mks_intVec*)malloc(sizeof(mks_intVec));
  res->len = 0;
  res->upper = numElems;
  res->data = (MKS_VEC_T*)malloc(res->upper * sizeof(MKS_VEC_T));
  return res; 
}

void mks_intVecFree(mks_intVec* in)
{
  free(in->data);
  free(in);
}

void mks_intVecReserve(mks_intVec* in, size_t newUpper)
{
  if (newUpper < in->upper) raise(EINVAL, "Can't reserve less data then is already availible");
  in->upper = newUpper;
  in->data = (MKS_VEC_T*)realloc(in->data, in->upper * sizeof(MKS_VEC_T));
}

void mks_intVecRealloc(mks_intVec* in)
{
  in->upper *= 2;
  in->data = (MKS_VEC_T*)realloc(in->data, in->upper * sizeof(MKS_VEC_T));
}

void mks_intVecSetVal(mks_intVec* in, MKS_VEC_T value, size_t index)
{
  if (index > in->upper - 1) mks_intVecRealloc(in);
  
  in->data[index] = value;
  in->len++;
}

MKS_VEC_T mks_intVecGetVal(mks_intVec* in, size_t index)
{
  if (index > in->len) raise(EINVAL, "Index is out of bounds");
  return in->data[index];
}