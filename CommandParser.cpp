#include "CommandParser.h"
#include "CountDown.h"
#include "RollerController.h"

void CommandParser::parse(String command, RollerController &rollerController) {
  // Fjern førende mellemrum
  command.trim();

  // Tjek om kommandoen er "RUL_OP"
  if (command == "RUL_OP") {

    rollerController.rollUp();
    
  } 

  // Tjek om kommandoen er "RUL_NED"
  else if (command == "RUL_NED") {
    rollerController.rollDown();
  } 

  // Tjek om kommandoen starter med "INDSTIL:AUTO="
  else if (command.startsWith("INDSTIL:AUTO=")) {
    // Find indekset for "AUTO=" og "MODE="
    int autoIndex = command.indexOf("AUTO=");
    int modeIndex = command.indexOf("MODE=");

    // Afgør om auto-tilstand er slået til eller fra
    bool autoEnabled = command.substring(autoIndex + 5, autoIndex + 7) == "ON";

    // Udtræk tilstandsstrengen og indstil auto-tilstand derefter
    String modeStr = command.substring(modeIndex + 5, modeIndex + 9);
    rollerController.setAutoEnabled(autoEnabled);
    if (modeStr == "TIME") {
      rollerController.setAutoMode(AutoSettings::TIME);
    } else if (modeStr == "LIGHT") {
      rollerController.setAutoMode(AutoSettings::LIGHT);
    }
  } 

   else if (command.startsWith("INDSTIL:NEDTÆLLING=")) {
    // Find the index for "NEDTÆLLING=" and "TID="
    int countdownIndex = command.indexOf("NEDTÆLLING=");
    int timeIndex = command.indexOf("TID=");

    // Extract targetHourUp, targetMinuteUp, targetHourDown, targetMinuteDown
    int targetHourUp = parseInt(command.substring(countdownIndex + 11, countdownIndex + 13));
    int targetMinuteUp = parseInt(command.substring(countdownIndex + 14, countdownIndex + 16));
    int targetHourDown = parseInt(command.substring(countdownIndex + 17, countdownIndex + 19));
    int targetMinuteDown = parseInt(command.substring(countdownIndex + 20, countdownIndex + 22));

    // Extract currentHour, currentMinute, and currentSecond
    int currentHour = parseInt(command.substring(timeIndex + 4, timeIndex + 6));
    int currentMinute = parseInt(command.substring(timeIndex + 7, timeIndex + 9));
    int currentSecond = parseInt(command.substring(timeIndex + 10, timeIndex + 12));

    // Call the countdown function with the extracted time and an action
    void countdown(int currentHour, int currentMinute, int currentSecond, int targetHourUp, int targetMinuteUp, int targetHourDown, int targetMinuteDown, RollerController &RollerController);
  }


  // Tjek om kommandoen starter med "INDSTIL:TIME_UP="
  else if (command.startsWith("INDSTIL:TIME_UP=")) {
    // Find indekset for "TIME_UP=" og "TIME_DOWN="
    int timeUpIndex = command.indexOf("TIME_UP=");
    int timeDownIndex = command.indexOf("TIME_DOWN=");

    // Udtræk tidspunkterne for op og ned og indstil auto-tiderne derefter
    int upHour = parseInt(command.substring(timeUpIndex + 8, timeUpIndex + 10));
    int upMinute = parseInt(command.substring(timeUpIndex + 11, timeUpIndex + 13));
    int downHour = parseInt(command.substring(timeDownIndex + 10, timeDownIndex + 12));
    int downMinute = parseInt(command.substring(timeDownIndex + 13, timeDownIndex + 15));

    rollerController.setAutoTimes(upHour, upMinute, downHour, downMinute);
  }
}

int CommandParser::parseInt(String str) {
  int result = 0;
  bool negative = false;
  int i = 0;

  if (str.charAt(0) == '-') {
    negative = true;
    i++;
  }

  for (; i < str.length(); i++) {
    char c = str.charAt(i);
    if (c >= '0' && c <= '9') {
      result = result * 10 + (c - '0');
    }
  }

  if (negative) {
    result = -result;
  }

  return result;
}
