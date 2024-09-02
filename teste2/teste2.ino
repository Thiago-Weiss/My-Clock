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
class Button {
private:
  byte timeBounce = BUTTON_BOUNCE;
  byte timePress = BUTTON_PRESS;
  unsigned int lastMove = 0;
  bool last_status = true;
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

    if (time < timeBounce) return;  // check bounce

    if (status == last_status) {          // check switch state
      if (status and time > timePress) {  // check button press
        if (funcPress != nullptr) {
          funcPress(value, maxValue);
        }
      }
      return;
    }

    lastMove = millis();
    last_status = status;

    if (status) {  // check pressed
      if (funcPressed != nullptr) {
        funcPressed(value, maxValue);
      }
    } else {  // check relesed
      if (funcRelease != nullptr) {
        funcRelease(value, maxValue);
      }
    }
  }
};
//==========================================




//==========================================
/////////////// vars ///////////////////////
byte asd = 10; //controle
//   alarme        hh mm d  s  t  q  q  s  s
byte alarme1[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
byte alarme2[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

byte *alarmes[] = { alarme1, alarme2 };
byte maxAlarme[] = { 24, 60, 1, 1, 1, 1, 1, 1, 1 };

byte posAlarme = 0;
byte posAlarmeLimite = 9;

// telas
byte telaAtual = 0;
byte telaLimite = 3;

// text
String linha1;
String linha2;

// buttons
extern Button bnt1;
extern Button bnt2;
extern Button bnt3;

// funcs
extern void (*bntFuncs[])(byte *, byte);

//==========================================
/////////////// funcs //////////////////////
void nextVal(byte *val, byte maxVal);
void switchWindows(byte *val, byte maxVal);
void clearBnt(Button bnt);
void displayText();
void showMenu();
String dayOfWeek(int dayW);
void showAlarm();




void nextVal(byte *val, byte maxVal) {
  *val += 1;
  if (*val >= maxVal) *val = 0;
  Serial.println(*val);
}


void switchWindows(byte *val, byte maxVal) {
  nextVal(val, maxVal);
  lcd.clear();

  switch (telaAtual) {
    case 0:
      {
        clearBnt(&bnt2);
        clearBnt(&bnt3);
        break;
      }
    case 1:
    case 2:
      {
        posAlarme = 0;
        bnt2.setPresed(nextVal);
        //bnt2.setPress(nextVal);
        bnt2.setValue(&posAlarme);
        bnt2.setValue(posAlarmeLimite);

        bnt3.setPresed(nextVal);
        //bnt3.setPress(nextVal);
        bnt3.setValue(&alarmes[telaAtual - 1][posAlarme]);
        bnt3.setValue(maxAlarme[posAlarme]);
        break;
      }
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
    case 0:
      {
        showMenu();
        break;
      }
    case 1:
    case 2:
      {
        showAlarm();
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
    default : return " ";
  }
}

void showAlarm() {
  linha1 = "";
  byte val= alarmes[telaAtual - 1][0];
  String text = String(val);
  text = (val < 10 ? "0" + text : text);
  linha1 += (posAlarme == 0 ? ">" + text + "<" : " " + text + " ");
  linha1 += ":";

  val = alarmes[telaAtual - 1][1];
  text = String(val);
  text = (val < 10 ? "0" + text : text);
  linha1 += (posAlarme == 1 ? ">" + text + "<" : " " + text + " ");
  linha1 += "alarm " + String(telaAtual);

  linha2 = (posAlarme == 2 ? "" : " ");
  for (int i = 2; i < posAlarmeLimite; i++) {
    char texte = dayOfWeek(i-1)[0] + ('a' - 'A');
    if (posAlarme == i) {
      linha2 += ">";
      linha2 += String(texte);
      linha2 += "<";
      continue;
    }
    linha2 += String(texte);
    linha2 += (i == posAlarmeLimite - 1 ? " " : "-");
  }
}




void (*bntFuncs[])(byte *, byte) = { nullptr, nextVal };









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

