#include "Button.h"

Button::Button(byte p, void (*func)(byte *val, byte maxVal), byte *val, byte maxVal)
  : lastMove(0), lastStatus(true), digPin(p), click(func), value(val), maxValue(maxVal) {
  pinMode(digPin, INPUT);
}

void Button::setClick(void (*func)()) {
  click = func;
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
    callClick();
    lastStatus = status;
    lastMove = millis();
    return;
  }

  if (!status) return;

  if (!lastStatus) {  // click
    callClick();
    lastStatus = status;
    lastMove = millis();
    return;
  }

  if (time > BUTTON_PRESS) {  // press
    callClick();
    lastMove += PRESS_SECONDS;
  }
}

void Button::callClick() {
  if (click != nullptr) {
    click(value, maxValue);
  }
}


