#include "Button.h"

Button::Button(byte p, void (*pressed)(byte *val, byte maxVal), byte *val, byte maxVal)
  : lastMove(0), lastStatus(true), digPin(p), funcPressed(pressed), value(val), maxValue(maxVal) {
  pinMode(digPin, INPUT);
}

void Button::setPresed(void (*presed)()) {
  funcPressed = presed;
}

void Button::setPress(void (*press)()) {
  funcPress = press;
}

void Button::setRelease(void (*release)()) {
  funcRelease = release;
}

void Button::setValue(byte *val) {
  value = val;
}

void Button::setMaxValue(byte maxVal) {
  maxValue = maxVal;
}

void Button::att() {
  bool status = digitalRead(digPin);
  unsigned int time = millis() - lastMove;

  if (time < BUTTON_BOUNCE) return;  // check bounce

  if (!status && lastStatus) {  // check release
    release();
    lastStatus = status;
    lastMove = millis();
    return;
  }

  if (!status) return;

  if (!lastStatus) {  // pressed
    pressed();
    lastStatus = status;
    lastMove = millis();
    return;
  }

  if (time > BUTTON_PRESS) {  // press
    press();
    lastMove += PRESS_SECONDS;
  }
}

void Button::pressed() {
  if (funcPressed != nullptr) {
    funcPressed(value, maxValue);
  }
}

void Button::press() {
  if (funcPress != nullptr) {
    funcPress(value, maxValue);
  }
}

void Button::release() {
  if (funcRelease != nullptr) {
    funcRelease(value, maxValue);
  }
}
