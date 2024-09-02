#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//==========================================
/////////////// class lcd //////////////////
#define LCD_ADDRESS 0x27
LiquidCrystal_I2C lcd(LCD_ADDRESS, 16, 2);
//==========================================



//==========================================
/////////////// class button ///////////////
#define BUTTON_BOUNCE 50
#define BUTTON_PRESS 800
#define PRESS_SECONDS 150
class Button {
private:
  unsigned int lastMove = 0;
  bool lastStatus = true;
  byte digPin;
  void (*funcPressed)(byte *val, byte maxVal) = nullptr;
  void (*funcRelease)(byte *val, byte maxVal) = nullptr;
  void (*funcPress)(byte *val, byte maxVal) = nullptr;
  byte *value;
  byte maxValue;


public:
  Button(byte p, void (*pressed)(byte *val, byte maxVal), byte *val, byte maxVal) {
    digPin = p;
    pinMode(digPin, INPUT);
    funcPressed = pressed;
    value = val;
    maxValue = maxVal;
  }

  void setPresed(void (*presed)()) {
    funcPressed = presed;
  }

  void setPress(void (*press)()) {
    funcPress = press;
  }

  void setRelease(void (*release)()) {
    funcRelease = release;
  }

  void setValue(byte *val) {
    value = val;
  }

  void setMaxValue(byte maxVal) {
    maxValue = maxVal;
  }



  // step
  void att() {
    bool status = digitalRead(digPin);
    unsigned int time = millis() - lastMove;

    if (time < BUTTON_BOUNCE) return;  // check bounce

    if (!status and lastStatus) {  // check release
      release();
      lastStatus = status;
      lastMove = millis();
      return;
    }

    if (!status) return;

    if (!lastStatus) {  //pressed
      pressed();
      lastStatus = status;
      lastMove = millis();
      return;
    }

    if (time > BUTTON_PRESS) {  //press
      press();
      lastMove += PRESS_SECONDS;
    }
  }

private:
  void pressed() {
    if (funcPressed != nullptr) {
      funcPressed(value, maxValue);
    }
  }

  void press() {
    if (funcPress != nullptr) {
      funcPress(value, maxValue);
    }
  }

  void release() {
    if (funcRelease != nullptr) {
      funcRelease(value, maxValue);
    }
  }
};
//==========================================




//==========================================
/////////////// vars ///////////////////////
byte asd = 10;  //controle

enum SCREENS {
    MENU,    
    ALARME_1,    
    ALARME_2,    
    CONFIG_ALARME   
};

//   alarme        hh mm d  s  t  q  q  s  s
byte alarme1[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
byte alarme2[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

byte *alarmes[] = { alarme1, alarme2 };
byte maxAlarme[] = { 24, 60, 2, 2, 2, 2, 2, 2, 2 };

byte posAlarme = 0;
byte posAlarmeLimite = 9;

// data         hh:dd - DD/MM/AA - d
byte data[] = { 0, 0, 0, 0, 0, 0 };
byte maxData[] = { 24, 60, 32, 13, 100, 7 };

byte posData = 0;
byte posDataLimite = 6;

// telas
byte telaAtual = 0;
byte telaLimite = 4;

// text
String linha1;
String linha2;

// buttons
extern Button bnt1;
extern Button bnt2;
extern Button bnt3;


//==========================================
/////////////// funcs //////////////////////
void nextVal(byte *val, byte maxVal);
void nextValData(byte *val, byte maxVal);
void nextValAlarm(byte *val, byte maxVal);

void switchWindows(byte *val, byte maxVal);
void clearBnt(Button bnt);

void displayText();
void showMenu();
void showAlarm();
void showConfigData();

String dayOfWeek(int dayW);
String formatText(byte val, bool sinal);
String numToText(byte val);


//==========================================
/////////////// funcs //////////////////////
void nextVal(byte *val, byte maxVal) {
  *val += 1;
  if (*val >= maxVal) *val = 0;
  Serial.println(*val);
}

void nextValAlarm(byte *val, byte maxVal) {
  nextVal(val, maxVal);
  bnt3.setValue(&alarmes[telaAtual - 1][posAlarme]);
  bnt3.setMaxValue(maxAlarme[posAlarme]);
}

void nextValData(byte *val, byte maxVal) {
  nextVal(val, maxVal);
  bnt3.setValue(&data[posData]);
  bnt3.setMaxValue(maxData[posData]);
}


void switchWindows(byte *val, byte maxVal) {
  nextVal(val, maxVal);
  lcd.clear();

  switch (telaAtual) {
    case MENU:
      {
        clearBnt(&bnt2);
        clearBnt(&bnt3);
        break;
      }
    case ALARME_1:
    case ALARME_2:
      {
        posAlarme = 0;
        bnt2.setPresed(nextValAlarm);
        bnt2.setPress(nextValAlarm);
        bnt2.setValue(&posAlarme);
        bnt2.setMaxValue(posAlarmeLimite);

        bnt3.setPresed(nextVal);
        bnt3.setPress(nextVal);
        bnt3.setValue(&alarmes[telaAtual - 1][posAlarme]);
        bnt3.setMaxValue(maxAlarme[posAlarme]);
        break;
      }
    case CONFIG_ALARME:
      posData = 0;
      bnt2.setPresed(nextValData);
      bnt2.setPress(nextValData);
      bnt2.setValue(&posData);
      bnt2.setMaxValue(posDataLimite);

      bnt3.setPresed(nextVal);
      bnt3.setPress(nextVal);
      bnt3.setValue(&data[posData]);
      bnt3.setMaxValue(maxData[posData]);
  }
}
void clearBnt(Button *bnt) {
  Serial.println("aqui");
  bnt->setPresed(nullptr);
  bnt->setPress(nullptr);
  bnt->setRelease(nullptr);
  bnt->setValue(&asd);
  bnt->setMaxValue(10);
}

void displayText() {
  linha1 = "";
  linha2 = "";

  switch (telaAtual) {
    case MENU:
      {
        showMenu();
        break;
      }
    case ALARME_1:
    case ALARME_2:
      {
        showAlarm();
        break;
      }
    case CONFIG_ALARME:
      {
        showConfigData();
        break;
      }
  }
  lcd.setCursor(0, 0);
  lcd.print(linha1);
  lcd.setCursor(0, 1);
  lcd.print(linha2);
}

void showMenu() {
  linha1 = "hh:mm:ss sabado ";
  linha2 = "   dd/mm/aaaa   ";

  /*
  myRTC.updateTime();
  linha1 += (myRTC.hours < 10 ? "0" : "") + String(myRTC.hours) + ":";
  linha1 += (myRTC.minutes < 10 ? "0" : "") + String(myRTC.minutes) + ":";
  linha1 += (myRTC.seconds < 10 ? "0" : "") + String(myRTC.seconds) + " ";
  linha1 += dayOfWeek(myRTC.dayofweek);
  lcd.setCursor(0, 0); 
  lcd.print(linha1);

  linha2 += "-- ";
  linha2 += (myRTC.dayofmonth < 10 ? "0": "") + String(myRTC.dayofmonth) + "/"
  linha2 += (myRTC.month < 10 ? "0": "") + String(myRTC.month) + "/"
  linha2 += String(myRTC.year);
  linha2 += " --";
  lcd.setCursor(0,1);
  lcd.print(linha2);
*/
}

String dayOfWeek(int dayW) {
  switch (dayW) {
    case 1: return "Domingo";
    case 2: return "Segunda";
    case 3: return "Terca  ";
    case 4: return "Quarta ";
    case 5: return "Quinta ";
    case 6: return "Sexta  ";
    case 7: return "Sabado ";
    default: return " ";
  }
}

String numToText(byte val){
  String text = String(val);
  text = (val < 10 ? "0" + text : text);
  return text;
}

String formatText(byte val, bool sinal){
  String text = numToText(val);
  return (sinal ? ">" + text + "<" : " " + text + " ");
}


void showAlarm() {
  linha1 += formatText(alarmes[telaAtual - 1][0], posAlarme == 0);
  linha1 += ":";
  linha1 += formatText(alarmes[telaAtual - 1][1], posAlarme == 1);
  linha1 += "alarm " + String(telaAtual);

  linha2 = (posAlarme == 2 ? "" : " ");
  for (int i = 2; i < posAlarmeLimite; i++) {
    char letra = dayOfWeek(i - 1)[0] + (alarmes[telaAtual - 1][i] ? 0 : ('a' - 'A'));
    if (posAlarme == i) {
      linha2 += ">";
      linha2 += String(letra);
      linha2 += "<";
      continue;
    }
    linha2 += String(letra);
    linha2 += (i == posAlarmeLimite - 1 || i + 1 == posAlarme ? "" : "-");
  }
  linha2 += "  ";
}



void showConfigData() {
  linha1 = "";
  String text = "";


  linha1 += formatText(data[0], posData == 0);
  linha1 += ":";
  linha1 += formatText(data[1], posData == 1);
  linha1 += " data  " ;

  linha2 = (posData == 2 ? "" : " ");
  for (int i = 2; i < posDataLimite - 1; i++) {
    text = numToText(data[i]);

    if (posData == i){
      linha2 += ">";
      linha2 += text;
      linha2 += "<";
      continue;
    }
    linha2 += text;
    linha2 += (i == posDataLimite - 2 || i + 1 == posData ? "" : "/");
  }
  linha2 += (posData == 4 ? "dia" : " dia");
  text = dayOfWeek(data[5] + 1)[0];
  linha2 += (posData == 5 ? ">" + text + "<" : " " + text + " ");
}

#define BNT_PIN1 4
#define BNT_PIN2 7
#define BNT_PIN3 8

Button bnt1(BNT_PIN1, switchWindows, &telaAtual, telaLimite);
Button bnt2(BNT_PIN2, nullptr, &asd, 10);
Button bnt3(BNT_PIN3, nullptr, &asd, 10);


void setup() {
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.clear();
}


void loop() {
  bnt1.att();
  bnt2.att();
  bnt3.att();
  displayText();
}