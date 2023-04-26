
#include "RollerController.h"
#include "CommandParser.h"
#include "Arduino.h"

RollerController rollerController;
CommandParser commandParser;

void setup() {
  Serial.begin(9600);
  rollerController.setup();
}

void loop() {
  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');
    commandParser.parse(command, rollerController);
  }
  rollerController.update();
  
}
