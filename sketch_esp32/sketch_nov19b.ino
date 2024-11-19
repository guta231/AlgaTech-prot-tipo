#include <WiFi.h>
#include <PubSubClient.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// Define o pino onde o sensor está conectado
#define ONE_WIRE_BUS 2

// Configura o barramento OneWire
OneWire oneWire(ONE_WIRE_BUS);

// Passa o barramento OneWire para a biblioteca DallasTemperature
DallasTemperature sensors(&oneWire);

// Credenciais Wi-Fi e IP do broker MQTT
const char* ssid = "CLARO_2G5B97A8";
const char* password = "Marcilene18";
const char* IP_MQTT = "20.206.203.145";

// Inicialização dos objetos WiFi e MQTT
WiFiClient espClient;
PubSubClient client(espClient);

// Função para conectar ao Wi-Fi
void wificonnect() {
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print("Conectando ao Wi-Fi");
    WiFi.begin(ssid, password); // Chama WiFi.begin() apenas uma vez
    while (WiFi.status() != WL_CONNECTED) { // Aguarda a conexão
      delay(500);
      Serial.print(".");
    }
    Serial.println("\nWi-Fi conectado!");
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
  }
}

void setup() {
  // Inicializa comunicação serial e configurações MQTT
  Serial.begin(9600);
  client.setServer(IP_MQTT, 1883);
  wificonnect(); // Conecta ao Wi-Fi
  sensors.begin(); // Inicializa o sensor de temperatura
}

void loop() {
  // Verifica se o cliente MQTT está conectado
  if (!client.connected()) {
    Serial.print("Reconectando ao broker MQTT...");
    if (client.connect("device001")) {
      Serial.println(" Conectado!");
    } else {
      Serial.println(" Falha na conexão. Tentando novamente...");
      delay(5000); // Aguarda 5 segundos antes de tentar novamente
      return;
    }
  }

  // Mantém a conexão Wi-Fi
  if (WiFi.status() != WL_CONNECTED) {
    wificonnect();
  }

  // Publica mensagens recebidas via UART
  if (Serial.available()) {
    String uartMessage = Serial.readStringUntil('\n'); // Lê a mensagem até '\n'
    Serial.print("Mensagem recebida via UART: ");
    Serial.println(uartMessage);
    client.publish("/TEF/device001/attrs/luminosidade", uartMessage.c_str());
  }

  // Atualiza a leitura de temperatura
  sensors.requestTemperatures(); // Solicita uma nova leitura
  float tempC = sensors.getTempCByIndex(0); // Obtém a temperatura em °C

  if (tempC != DEVICE_DISCONNECTED_C) { // Verifica se o sensor está conectado
    Serial.print("Temperatura: ");
    Serial.print(tempC);
    Serial.println(" °C");
    client.publish("/TEF/device001/attrs/temperatura", String(tempC).c_str());
  } else {
    Serial.println("Erro: Sensor desconectado!");
  }

  client.loop(); // Mantém a comunicação MQTT
}
