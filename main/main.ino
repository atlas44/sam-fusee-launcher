

#include <FlashAsEEPROM.h>

#include "fuseegelee.h"
#include "trinketLed.h"

// Contains fuseeBin and FUSEE_BIN_LENGTH
#include "hekate_ctcaer_3.0.h"
#include "sxLoader.h"


void setup()
{
  ledInit();
  if (usbInit() == -1) sleepDeep(-1);

  int currentTime = 0;
  while (!searchTegraDevice())
  {
    currentTime = millis();
    ledBlink("orange", 1, 200);
  }

  setupTegraDevice();

  sendPayload(sx_loader, SX_LOADER_SIZE);

  launchPayload();

  sleepDeep(1);
}

void loop()
{
}
