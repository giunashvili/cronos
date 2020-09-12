#include "../types/sql.t.h"
#include "/usr/local/mysql/include/mysql.h"

/**
 *  Connect to mysql client. 
 *  
 *  @return MYSQL*
 */
MYSQL*      connect();

/** 
 * Get Response from sql query execution.
 * 
 * @param MYSQL* connection
 * @param char*  sqlQuery
 * @return MYSQL_RES*
*/
MYSQL_RES*  getResponse(MYSQL* connection, char* sqlQuery);

/** 
 * Output data in the browser.
 * 
 * @param MYSQL_RES* response
 * @return void
*/
void        outputData(MYSQL_RES* response);

/** 
 * Output data in the browser.
 * 
 * @param MYSQL_RES* response
 * @return void
*/
TABLE        getTableNames(MYSQL_RES* response);

/**
 * Execute query and print results.
 * 
 * @param char* query
 * @return void
 */