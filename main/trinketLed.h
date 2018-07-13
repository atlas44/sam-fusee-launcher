#include <Arduino.h>
#include <Adafruit_DotStar.h>
Adafruit_DotStar strip = Adafruit_DotStar(1, INTERNAL_DS_DATA, INTERNAL_DS_CLK, DOTSTAR_BGR);

void ledInit() {
  strip.begin();
}

void setLedColor(const char color[]) {
  if (color == "red") {
    strip.setPixelColor(0, 64, 0, 0);
  } else if (color == "green") {
    strip.setPixelColor(0, 0, 64, 0);
  } else if (color == "orange") {
    strip.setPixelColor(0, 64, 32, 0);
  } else if (color == "black") {
    strip.setPixelColor(0, 0, 0, 0);
  } else if (color == "blue") {
    strip.setPixelColor(0, 5, 20, 64);
  } else if (color == "red2") {
    strip.setPixelColor(0, 64, 10, 10);
  } else {
    strip.setPixelColor(0, 255, 255, 255);
  }
  strip.show();
}

void ledBlink(const char color[], int count, int duration) {
  for (int counter = 0; counter < count; counter++) {
    for (int onOff = 1; onOff >= 0; onOff--) {
      if (onOff == 1) {
        setLedColor(color);
      } else {
        setLedColor("black");
      }
      delay(duration / (2.0 * count));
    }
  }
}

void sleepDeep(int errorCode) {
  // Turn off all LEDs and go to sleep. To launch another payload, press the reset button on the device.
  //delay(100);
  digitalWrite(PIN_LED_RXL, HIGH);
  digitalWrite(PIN_LED_TXL, HIGH);
  digitalWrite(13, LOW);
  if (errorCode == 1) {
    setLedColor("black");; //led to off
  } else {
    setLedColor("red"); //led to red
  }
  SCB->SCR |= SCB_SCR_SLEEPDEEP_Msk; /* Enable deepsleep */
  __DSB(); /* Ensure effect of last store takes effect */
  __WFI(); /* Enter sleep mode */
}
