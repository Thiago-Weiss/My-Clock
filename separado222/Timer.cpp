#include "Timer.h"


Timer::Timer(int time, void (*function)())
  : timer(time), func(function), active(true) {
  startTime = millis();
}

void Timer::reset() {
  active = true;
  startTime = millis();
}

void Timer::stop() {
  active = false;
}

void Timer::setFunc(void (*function)()) {
  func = function;
}

void Timer::att() {
  if (!active) return;

  unsigned int time = millis() - startTime;
  if (time > timer) {
    active = false;
    if (func != nullptr) {
      func();
    }
  }
}











