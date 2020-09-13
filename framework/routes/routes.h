#ifndef CRONOS_ROUTES
#define CRONOS_ROUTES

#include "libs/router.h"

void registerRoutes()
{
  route("GET:/", "landing", "index");
}

#endif