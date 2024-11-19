#include <WiFi.h>
#include <PubSubClient.h>

// Credenciais Wi-Fi e IP do broker MQTT
const char* ssid = "A34 de Gustavo";
const char* password = "gustavogostoso";
const char* IP_MQTT = "20.206.203.145";

// Inicialização dos objetos WiFi e MQTT
WiFiClient espClient;
PubSubClient client(espClient);

// Função para conectar ao Wi-Fi
void wificonnect() {
  if (WiFi.status() != WL_CONNECTED) {
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
    }
  }

  // Publica mensagens recebidas via UART
  if (Serial.available()) {
    String uartMessage = Serial.readStringUntil('\n'); // Lê a mensagem até '\n'
    Serial.print("Mensagem recebida via UART: ");
    Serial.println(uartMessage);
    client.publish("/TEF/device001/attrs/temperature&umidade", uartMessage.c_str());
  }

  client.loop(); // Mantém a comunicação MQTT
}
