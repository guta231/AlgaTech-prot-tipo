#include <OneWire.h>
#include <DallasTemperature.h>

// Define o pino onde o sensor está conectado
#define ONE_WIRE_BUS 2

// Configura o barramento OneWire
OneWire oneWire(ONE_WIRE_BUS);

// Passa o barramento OneWire para a biblioteca DallasTemperature
DallasTemperature sensors(&oneWire);

void setup() {
  // Inicia a comunicação serial
  Serial.begin(9600);
  // Inicia os sensores
  sensors.begin();

  pinMode(A0, INPUT);
}

void loop() {
  // Solicita aos sensores para obter a leitura da temperatura
  sensors.requestTemperatures();

  int luminosidade = analogRead(A0);
  Serial.print("Luminosidade: ");
  Serial.println(luminosidade);
  
  // Exibe a temperatura na Serial Monitor
  float tempC = sensors.getTempCByIndex(0); // Temperatura em °C
  Serial.print("Temperatura: ");
  Serial.print(tempC);
  Serial.println(" °C");
  
  // Espera 1 segundo antes de ler novamente
  delay(1000);
}
