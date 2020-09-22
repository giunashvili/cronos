#include <stdio.h>
#include <string.h>

int delimiterPosition(char* req);
bool matchPath(char* request, int* pos);

void route(char* request, void (*meth)(void))
{
  const char* method  = getenv("REQUEST_METHOD");
  int position = delimiterPosition(request);

  if(matchPath(request, &position))
  {
    (*meth)();
    exit(0);
  }
}

int delimiterPosition(char* req)
{
  int position = 0;

  while(*req != '\0')
  {
    if( *req == ':' )
    {
      return position;
    }
    position++;
    req++;
  }

  return -1;
}

bool matchPath(char* request, int* pos)
{
  const char* uri = getenv("REQUEST_URI");
  const int requestLength = strlen(request);
  const int uriLength = strlen(uri);

  int x, y, i;
  for(int i=1; i<=uriLength; i++)
  {
    x = requestLength - i;
    y = uriLength - i;

    if(*(request+x) != *(uri+y))
    {
      return false;
    }
  }

  return true;
}