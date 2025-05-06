#include <Arduino.h>

const int rainSensorPin = 35;           // Pino analógico do sensor de chuva
unsigned long lastCheckTime = 0;        // Tempo da última leitura
const unsigned long interval = 1000;    // Intervalo de leitura (1 segundo)

void setup() {
  Serial.begin(9600);
  Serial.println("Sensor de chuva iniciado...");
}

void loop() {
  unsigned long currentTime = millis();

  if (currentTime - lastCheckTime >= interval) {
    lastCheckTime = currentTime;

    int rainValue = analogRead(rainSensorPin);

    // O sensor retorna valores mais baixos quando molhado
    // Ajuste os valores conforme seu sensor e testes
    int intensity = map(rainValue, 2500, 500, 0, 10);
    intensity = constrain(intensity, 0, 10);

    if (intensity > 0) {
      Serial.print("☔ Chuva detectada! Intensidade: ");
      Serial.println(intensity);
    }

    else 
    {
      Serial.println("seco");
    }
  }

  // Código livre para outras tarefas sem travar
}


