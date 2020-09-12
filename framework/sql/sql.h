#include "interface.h"
#include "../types/sql.t.h"
#include "../headers/env.h"
#include "../headers/helpers.h"
#include "/usr/local/mysql/include/mysql.h"


void query(char* query)
{ 
  setContentToHTML();
  MYSQL* connection = connect();
  
  if (! connection ) 
  {
    printf("%s\n", mysql_error(connection));
    return;
  }

  MYSQL_RES* response = getResponse(connection, query);

  outputData( response );

  mysql_free_result(response);
  mysql_close(connection);
}

/**
 * Describe tables.
 * 
 * @param char* table
 * @return void
 */
void describe(char* table)
{
  setContentToHTML();
  MYSQL* connection = connect();
  
  if (! connection ) 
  {
    printf("%s\n", mysql_error(connection));
    return;
  }

  MYSQL_RES* response = getResponse(connection, table);
  TABLE tableInfo = getTableNames(response);


  br();
  br();
  printf("%s", tableInfo.columnsList[1]);
  return;
  for(int i=0; i < tableInfo.columnsCount; i++ )
  {
    write(tableInfo.columnsList[i]);
    br();
  }

  mysql_free_result(response);
  mysql_close(connection);
}

MYSQL* connect()
{
  MYSQL* conn;
  conn = mysql_init(NULL);
  
  return mysql_real_connect(conn, SERVER, USER, PASSWORD, DATABASE, 0, NULL, 0);
}

MYSQL_RES* getResponse( MYSQL* connection, char* sqlQuery )
{
  MYSQL_RES* res;

  if(mysql_query(connection, sqlQuery)) 
  {
    printf("%s\n", mysql_error(connection));
    exit(0); 
  }

  return mysql_use_result(connection);
}

void outputData(MYSQL_RES* response)
{
  MYSQL_ROW  row;
  int n = response ->field_count;
  
  while ((row = mysql_fetch_row(response)) != NULL)
  { 
    for(int i=0; i< n; i++)
    {
      write(row[i]);
      br();
    }    
  }
}

TABLE getTableNames(MYSQL_RES* response)
{
  TABLE tableInfo;

  MYSQL_ROW  row;
  int n = response ->field_count;
  tableInfo.columnsCount = response ->field_count;

  int i = 0;
  COLUMN list[n];

  while ((row = mysql_fetch_row(response)) != NULL)
  { 
    list[i] = row[0];
  }

  tableInfo.columnsList = list;

  return tableInfo;
}