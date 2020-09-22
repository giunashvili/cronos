#include "stdio.h"

void route(char* request, void (*meth)(void))
{
  const char* method  = getenv("REQUEST_METHOD");
  const char* uri     = getenv("REQUEST_URI"); 
  (*meth)();
  exit(0);
}