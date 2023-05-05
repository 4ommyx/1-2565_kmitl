int LDR = A0;  //Analog (วัดความสว่าง)/ LDR

void setup() {
  Serial.begin(9600);
  pinMode(LDR,INPUT);
  

}

void loop() {
  int Light = analogRead(LDR);
  Serial.print("LDR = ");
  Serial.println(Light);
  delay(1000);
}
