#include "RollerController.h"

RollerController::RollerController() {}

void RollerController::setup() {
  // Initialize hardware, e.g., motor control pins



}

void RollerController::update() {
  _applyAutoSettings();
}

void RollerController::rollUp() {
  // Implement manual roll up
}

void RollerController::rollDown() {
  // Implement manual roll down
}

void RollerController::setAutoMode(AutoSettings::AutoMode mode) {
  _autoSettings.setAutoMode(mode);
}

void RollerController::setAutoEnabled(bool enabled) {
  _autoSettings.setAutoEnabled(enabled);
}

void RollerController::setAutoTimes(int upHour, int upMinute, int downHour, int downMinute) {
  _autoSettings.setAutoTimes(upHour, upMinute, downHour, downMinute);
}

void RollerController::_applyAutoSettings() {
  // Implement the logic to control the roller based on the current auto settings
}
