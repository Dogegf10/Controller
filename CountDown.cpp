// Countdown.cpp
#include "CountDown.h"

void countdown(int currentHour, int currentMinute, int currentSecond, int targetHourUp, int targetMinuteUp, int targetHourDown, int targetMinuteDown, RollerController &rollerController) 

{
  int remainingSecondsUp = (targetHourUp * 3600 + targetMinuteUp * 60) - (currentHour * 3600 + currentMinute * 60 + currentSecond);
  int remainingSecondsDown = (targetHourDown * 3600 + targetMinuteDown * 60) - (currentHour * 3600 + currentMinute * 60 + currentSecond);

  int maxRemainingSeconds = max(remainingSecondsUp, remainingSecondsDown);

  for (int i = maxRemainingSeconds; i >= 0; i--) {
    int hours = i / 3600;
    int minutes = (i % 3600) / 60;
    int seconds = i % 60;

    Serial.print("Tid tilbage: ");
    Serial.print(hours);
    Serial.print(":");
    Serial.print(minutes);
    Serial.print(":");
    Serial.println(seconds);

    if (i == remainingSecondsUp) {
      rollerController.rollUp();
    }

    if (i == remainingSecondsDown) {
      rollerController.rollDown();
    }

    delay(1000);
  }
}
