


void setup() {
  // Inicia a comunicação serial
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop() {
  // Solicita aos sensores para obter a leitura da temperatura
  sensors.requestTemperatures();

  int luminosidade = analogRead(A0);
  Serial.print("Luminosidade: ");
  Serial.println(luminosidade);
  
  // Espera 1 segundo antes de ler novamente
  delay(1000);
}
