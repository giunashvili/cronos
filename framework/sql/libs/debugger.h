#ifndef CRONOS_MYSQL_DEBUGGER
#define CRONOS_MYSQL_DEBUGGER

#include "types.h"
#include "stdio.h"
#include "../../headers/helpers.h"

void printResult( Result result )
{
  for(int i=0; i<result.numberOfRows; i++)
  {
    for(int j=0; j<result.numberOfFields; j++)
    {
      printf("[%s] ", result.records[i][j]);
    }
    br();
    br();
    br();
  }

  br();
  printf("OK");
}

#endif