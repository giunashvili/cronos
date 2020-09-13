#include "mysql.h"
#include "../config/env.h"

/**
 *  Connect to mysql client. 
 *  
 *  @return MYSQL*
 */
MYSQL*      connect()
{
  MYSQL* conn;
  conn = mysql_init(NULL);
  
  return mysql_real_connect(conn, SERVER, USER, PASSWORD, DATABASE, 0, NULL, 0);
}