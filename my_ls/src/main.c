#include <stdio.h>
#include <errno.h>
#include "my_ls.h"

int main(int argc, char** argv)
{
#ifndef __LS_DEBUG__
  switch(argc)
  {
    case 1: magic_ls("./"); break;
    case 2: magic_ls(argv[1]); break;
    default: errno = EINVAL; perror("Only 1 extra arg: the directory."); exit(EXIT_FAILURE);
  }
#else
  switch(argc)
  {
    case 1: test("./"); break;
    case 2: test(argv[1]); break;
    default: errno = EINVAL; perror("Only 1 extra arg: the directory."); exit(EXIT_FAILURE);
  }
#endif
  return 0;
}