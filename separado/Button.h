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
  void (*funcPressed)(byte *val, byte maxVal);
  void (*funcRelease)(byte *val, byte maxVal);
  void (*funcPress)(byte *val, byte maxVal);
  byte *value;
  byte maxValue;

public:
  Button(byte p, void (*pressed)(byte *val, byte maxVal), byte *val, byte maxVal);

  void setPresed(void (*presed)());
  void setPress(void (*press)());
  void setRelease(void (*release)());
  void setValue(byte *val);
  void setMaxValue(byte maxVal);
  void att();

private:
  void pressed();
  void press();
  void release();
};

#endif // BUTTON_H
