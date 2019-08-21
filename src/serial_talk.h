#include "Arduino.h"

enum{
  esp32_start,
  esp32_cmd,
  esp32_print
};

void espSend(int type, ...);
