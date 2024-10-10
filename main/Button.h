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
  bool pressed;
  bool press;
  bool release;
  const uint8_t digPin;
  void (*clickFunc)();


public:
  Button(uint8_t p, void (*func)(), bool pressed, bool press, bool release);

  void setClick(void (*func)());
  void att();

private:
  void callfunc();
};

#endif // BUTTON_H
