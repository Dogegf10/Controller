#include "AutoSettings.h"

AutoSettings::AutoSettings() {}  // Konstruktør for AutoSettings-klassen

void AutoSettings::setAutoMode(AutoMode mode) {
  mode_ = (mode == TIME || mode == LIGHT ? mode : LIGHT);   // Sætter automatiseringsmode (s)
}

void AutoSettings::setAutoEnabled(bool enabled) {
  enabled_ = enabled;   // Sætter om automatisering er aktiveret eller ej
}

void AutoSettings::setAutoTimes(int upHour, int upMinute, int downHour, int downMinute) {
  _upHour =  (upHour <= 23 || upHour >= 0 ? upHour : 0);       // Sætter time for hvornår automatisering skal slå til
  _upMinute = (upMinute <= 59 || upMinute >= 0 ? upMinute : 0);   // Sætter minut for hvornår automatisering skal slå til
  _downHour =  (downHour <= 23 || downHour >= 0 ? downHour : 0);   // Sætter time for hvornår automatisering skal slå fra
  _downMinute = (downMinute <= 59 || downMinute >= 0 ? downMinute : 0);   // Sætter minut for hvornår automatisering skal slå fra
}
