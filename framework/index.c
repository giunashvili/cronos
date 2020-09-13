#include "headers/view.h"
#include "sql/sql.h"
#include "sql/debugger.h"
#include "mysql.h"

int main(int argv, char** argc, char** envp)
{ 
  setContentToJSON();
  write("<meta charset=\"UTF-8\">");

  Result result = query("select * from chargers limit 10");
  printResult(result);

  return 0;
}