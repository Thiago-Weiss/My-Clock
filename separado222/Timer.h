#ifndef TIMER_H
#define TIMER_H

#include <Arduino.h>

class Timer {
private:
  unsigned int startTime;
  unsigned int timer;
  bool active;
  void (*func)();

public:
  Timer(int time, void (*func)());

  void reset();
  void stop();
  void setFunc(void (*function)());
  void att();
};

#endif  // TIMER_H
