#include <Adafruit_AHTX0.h>

Adafruit_AHTX0 aht;

void setup() {
  Serial.begin(9600);
  Serial.println("AHT10 Test");

  if (!aht.begin()) {
    Serial.println("Não foi possível encontrar o AHT10/AHT20. Verifique a conexão!");
    while (1) delay(10);
  }
  Serial.println("AHT10/AHT20 encontrado!");
}

void loop() {
  sensors_event_t humidity, temp;
  aht.getEvent(&humidity, &temp);

  Serial.print("Temperatura: ");
  Serial.print(temp.temperature);
  Serial.println(" C");

  Serial.print("Umidade: ");
  Serial.print(humidity.relative_humidity);
  Serial.println(" %");

  delay(2000); // Delay de 2 segundos
}
