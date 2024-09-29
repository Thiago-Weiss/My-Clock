#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

#define BUTTON_BOUNCE 50
#define BUTTON_PRESS 800
#define PRESS_SECONDS 150

class Button {
private:
  unsigned int lastMove;
  bool lastStatus;
  byte digPin;
  void (*click)(byte *val, byte maxVal);
  byte *value;
  byte maxValue;

public:
  Button(byte p, void (*func)(byte *val, byte maxVal), byte *val, byte maxVal);

  void setClick(void (*func)());

  void setValue(byte *val);
  void setMaxValue(byte maxVal);
  void att();

private:
void Button::callClick();


};

#endif // BUTTON_H
