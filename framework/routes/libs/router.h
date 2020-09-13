#include "stdio.h"
#include "string.h"

void route(char* request,char* file, char* resolver)
{
  const char* method  = getenv("REQUEST_METHOD");
  const char* uri     = getenv("REQUEST_URI");

  char* meth = strtok(request, ":");

  printf("%s", meth);
  exit(0);

  printf("this is the method - %s", meth);
  exit(0);
}