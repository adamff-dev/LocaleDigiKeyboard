#include "LocaleDigiKeyboard.h"

void setup() {
}


void loop() {
  LocaleDigiKeyboard.sendKeyStroke(0);
  LocaleDigiKeyboard.delay(2000);
  LocaleDigiKeyboard.println("!\"#$%&'()*+,-./0123456789:;<=>?ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^`_abcdefghijklmnopqrstuvwxyz{|}~ @");
}