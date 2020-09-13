#include "types.h"
#include "/usr/local/mysql/include/mysql.h"

Result readData(MYSQL_RES* response)
{
  MYSQL_ROW* rows = (MYSQL_ROW *) malloc( sizeof(MYSQL_ROW) * response->row_count );

  for(int i=0; i<response->row_count; i++)
  {
    rows[i] = mysql_fetch_row(response);
  }

  Result static data;
  data.numberOfFields = response->field_count;
  data.numberOfRows = response->row_count;
  data.records = rows;
  
  return data;
}