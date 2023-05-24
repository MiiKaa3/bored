#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>
#include "my_ls.h"

void alphabeticalSort(char** list, size_t listLim, size_t charLim)
{
  size_t i;
  bool didSwap = true;
  char temp[charLim];

  while (didSwap)
  {
    didSwap = false;
    for (i = 0; i < listLim; i++)
    {
      if (strcmp (list[i], list[i + 1]) > 0)
      {
        strcpy(temp, list[i]);
        strcpy(list[i], list[i + 1]);
        strcpy(list[i + 1], temp);
        didSwap = true;
      }
    }
    listLim--;
  }
}

int magic_ls(char* dir)
{
  struct dirent* d;
  DIR* dh = dir ? opendir(dir) : opendir("./");

  if (!dh)
  {
    if (errno == ENOENT)
      perror("No such directory.");
    else 
      perror("Cannot read directory.");
    exit(EXIT_FAILURE);
  }

  size_t listLim = 36;
  size_t charLim = 256;
  char** list = (char**)calloc(sizeof(char*), listLim);
  for (size_t i = 0; i < listLim; i++) list[i] = (char*)calloc(sizeof(char), charLim);

  size_t i = 0;
  while((d = readdir(dh)) != NULL)
  {
    if(d->d_name[0] == '.') continue;
    strcpy(list[i++], d->d_name);
  }

  alphabeticalSort(list, i - 1, charLim);

  i = 0;
  while(*(list[i])) printf("%s  ", list[i++]);
  printf("\n");

  for (size_t i = 0; i < listLim; i++) free(list[i]);
  free(list);

  return 0;
}

void test(char* dir)
{
  char* cmd = (char*)malloc(sizeof(char)*256);
  sprintf(cmd, "ls %s", dir);

  printf("linux ls:\n");
  system(cmd);

  printf("\nmagic ls:\n");
  magic_ls(dir);
}