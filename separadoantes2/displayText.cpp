#include "displayText.h"


//==========================================
/////////////// funcs //////////////////////
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
  linha2 += (myRTC.dayofmonth < 10 ? "0": "") + String(myRTC.dayofmonth) + "/";
  linha2 += (myRTC.month < 10 ? "0": "") + String(myRTC.month) + "/";
  linha2 += String(myRTC.year);
  linha2 += " --";
  lcd.setCursor(0,1);
  lcd.print(linha2);
*/
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
