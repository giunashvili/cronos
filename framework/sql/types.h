#ifndef CRONOS_MYSQL_TYPES
#define CRONOS_MYSQL_TYPES
#include "mysql.h"

typedef struct Result
{
  unsigned int numberOfRows;    // Number of results of mysql query
  unsigned int numberOfFields;  // Number of row fields.

  MYSQL_ROW* records; // mysql builtin rows.
} Result;

#endif