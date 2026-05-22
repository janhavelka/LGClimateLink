#include "App.h"

#ifdef ARDUINO

lgcl::App app;

void setup() {
  app.begin();
}

void loop() {
  app.loop();
}

#endif
