#include "libs/router.h"
#include "../../project/landing.h"
#include "../../project/about.h"

void registerRoutes()
{
  route("GET:/", &landingIndex);
  route("GET:/about", &aboutIndex);
}