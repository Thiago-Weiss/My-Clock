#include "Gvars.h"

#include "funcsBnt.h"
#include "utils.h"


//==========================================
/////////////// class RTC //////////////////
#define clk_PIN 3
#define dat_PIN 2
#define rst_PIN 5
virtuabotixRTC myRTC(clk_PIN, dat_PIN, rst_PIN);
//==========================================



//==========================================
/////////////// class temp //////////////////
Adafruit_AHTX0 sensorTemp;
//==========================================



//==========================================
/////////////// class LCD //////////////////

#define LCD_ADDRESS 0x27
LiquidCrystal_I2C lcd(LCD_ADDRESS, 16, 2);
//==========================================



//==========================================
/////////////// class Button ///////////////
#define BNT_PIN1 4
#define BNT_PIN2 7
#define BNT_PIN3 8

Button bnt1(BNT_PIN1, bnt_1_Funcs, true, true, false);
Button bnt2(BNT_PIN2, bnt_2_Funcs, true, true, false);
Button bnt3(BNT_PIN3, bnt_3_Funcs, true, true, false);
//==========================================



//==========================================
/////////////// class Timer ////////////////
Timer backMenuTimer(1000 * 30, backMenu);           // 10s
Timer displayOffTimer(1000 * 120, displayTurnOff);  // 60s
//==========================================



// cursor
uint8_t cursor = 0;


//   alarme        hh mm d  s  t  q  q  s  s
uint8_t alarme1[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
uint8_t alarme2[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
uint8_t const maxAlarme[] = { 24, 60, 2, 2, 2, 2, 2, 2, 2 };

// data        DD/MM/AA d  hh:mm Button
uint8_t data[] = { 0, 0, 0, 0, 0, 0, 0};
uint8_t const maxData[] = {32, 13, 100, 7, 24, 60, 1};

// telas
uint8_t currentWindows = MENU;

