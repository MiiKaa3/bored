#include <stdio.h>
#include "mks_intvec.h"

int main()
{
  mks_intVec* v = mks_intVecInitReserve(10);
  for (size_t i = 0; i < 20; i++) mks_intVecSetVal(v, (int)i, i);
  for (size_t i = 0; i < 20; i++) printf("%d, ", mks_intVecGetVal(v, i));

  printf("\n");
  mks_intVecFree(v);

  return 0;
}