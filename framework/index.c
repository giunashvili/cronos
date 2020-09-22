#include "sql/sql.h"
#include "headers/view.h"
#include "routes/routes.h"
#include "sql/libs/debugger.h"

int main(int argv, char** argc, char** envs)
{
  return registerRoutes(), 0;
}
