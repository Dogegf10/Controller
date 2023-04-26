#ifndef RollerController_h
#define RollerController_h

#include "AutoSettings.h"

class RollerController {
public:
  RollerController();
  void setup();
  void update();
  void rollUp();
  void rollDown();
  void setAutoMode(AutoSettings::AutoMode mode);
  void setAutoEnabled(bool enabled);
  void setAutoTimes(int upHour, int upMinute, int downHour, int downMinute);
private:
  AutoSettings _autoSettings;
  void _applyAutoSettings();
};

#endif
