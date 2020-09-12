#ifndef SQL_T
#define SQL_T

typedef struct FIELD
{
  char* name;
  char* value;
} FIELD;

typedef char* COLUMN;

typedef struct TABLE
{
  int columnsCount;
  COLUMN* columnsList;
} TABLE;

typedef FIELD** RECORD;


#endif