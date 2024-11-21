


void setup() {
 
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop() {
  

  int luminosidade = analogRead(A0);
  Serial.println(luminosidade);
  
 
  delay(1000);
}
