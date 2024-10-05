#include "Button.h"

Button::Button(uint8_t p, void (*func)(), bool pressed, bool press, bool release)
  : lastMove(0), lastStatus(false), digPin(p), clickFunc(func), pressed(pressed), press(press), release(release) {
  pinMode(digPin, INPUT);
}

void Button::setClick(void (*func)()) {
  clickFunc = func;
}

void Button::att() {
  bool status = digitalRead(digPin);
  unsigned int time = millis() - lastMove;

  if (time < BUTTON_BOUNCE) return;  // check bounce

  if (!status && lastStatus) {  // check release
    if (release) {
      callfunc();
    }
    lastStatus = status;
    lastMove = millis();
    return;
  }

  if (!status) return;

  if (!lastStatus) {  // pressed
    if (pressed) {
      callfunc();
    }
    lastStatus = status;
    lastMove = millis();
    return;
  }

  if (time > BUTTON_PRESS) {  // press
    if (press) {
      callfunc();
    }
    lastMove += PRESS_SECONDS;
  }
}

void Button::callfunc() {
  if (!nullptr) {
    clickFunc();
  }
}
