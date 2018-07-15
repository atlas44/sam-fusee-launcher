#include <Arduino.h>

#include "fuseegelee.h"
#include "trinketLed.h"

// Contains fuseeBin and FUSEE_BIN_SIZE
#include "sxLoader.h"


void setup()
{
  ledInit();
  if (usbInit() == -1) sleepDeep(-1);

  while (!searchTegraDevice())
  {
    ledBlink("orange", 1, 200);
  }

  setupTegraDevice();

  sendPayload(fuseeBin, FUSEE_BIN_SIZE);

  launchPayload();

  sleepDeep(1);
}

void loop()
{
}
