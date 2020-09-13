#include "mysql.h"
#include "libs/types.h"
#include "libs/reader.h"
#include "libs/responder.h"
#include "libs/connection.h"
#include "../headers/helpers.h"

Result query(char* query)
{ 
  MYSQL* connection = connect();
  
  if (! connection ) 
  {
    printf("%s\n", mysql_error(connection));
    exit(0);
  }

  MYSQL_RES* response = getResponse(connection, query);
  
  Result data = readData(response);
  
  mysql_free_result(response);
  mysql_close(connection);

  return data;
}