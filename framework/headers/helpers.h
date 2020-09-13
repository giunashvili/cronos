#ifndef HELPERS
#define HELPERS
#include "stdio.h"

void setContentToHTML()
{
  printf("Content-type: text/html\n\n");
}

void setContentToJSON()
{
  printf("Content-type: application/json\n\n");
}

void setUTF8()
{
  printf("<meta charset=\"UTF-8\">");
}

void printEnvs(char** envs)
{
  setContentToHTML();

  printf("<ul>");
  for( char** env = envs; *env != 0; env++ )
  {
    char* thisEnv =* env;
    printf("<li>%s</li>", thisEnv);
  }
  printf("</ul>");
}

void br()
{
  printf("<br>");
}

void write(char* str)
{
  printf("%s", str); 
}

void output(char * str)
{
  setContentToHTML();
  write(str);
}

#endif