#include "env.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "helpers.h"

int countChars( char *filePath )
{
  FILE* file  = fopen( filePath, "r" );
  int counter = 0;
  char c;
  while( (c = fgetc( file )) != EOF )
  {
    counter++;
  }
  fclose( file );
  
  return counter;
}

char* read( char* filePath )
{
  int   countedChars  = countChars( filePath );
  char* rawContent    = malloc( countedChars * sizeof(char) );
  FILE* viewContent   = fopen( filePath, "r" );

  int iterator = 0;
  char c;
  while( (c = fgetc( viewContent )) != EOF )
  {
    rawContent[iterator] = c;
    iterator++;
  }
  
  return rawContent;
}

void view( char* view )
{
  setContentToHTML();
  char fullViewPath[101];

  strcpy(fullViewPath, VIEW_RESOURCE_PATH );
  strcat(fullViewPath, view );
  strcat(fullViewPath, ".html" );

  char* output = read( fullViewPath );
  printf("%s", output);
  free( output );
}