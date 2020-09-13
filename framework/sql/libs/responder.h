#include "stdio.h"
#include "mysql.h"

/** 
 * Get Response from sql query execution.
 * 
 * @param MYSQL* connection
 * @param char*  sqlQuery
 * @return MYSQL_RES*
*/
MYSQL_RES* getResponse( MYSQL* connection, char* sqlQuery )
{
  MYSQL_RES* res;

  if(mysql_query(connection, sqlQuery)) 
  {
    printf("%s\n", mysql_error(connection));
    exit(0); 
  }

  return mysql_store_result(connection);
}