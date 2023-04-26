#ifndef CommandParser_h
#define CommandParser_h

#include "RollerController.h"
#include "Arduino.h"

class CommandParser {
public:
  // Funktionen parser den givne kommando og udfører den passende handling på rollerControlleren
  void parse(String command, RollerController &rollerController);

  // Funktionen parser den givne String og returnerer den integer-værdi, som den repræsenterer
  int parseInt(String str);
};

#endif
