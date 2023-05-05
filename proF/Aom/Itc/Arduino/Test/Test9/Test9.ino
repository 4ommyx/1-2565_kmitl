void setup() {
  Serial.begin(9600);

}

void loop() {
  for(int i = 0 ; i<=10000 ; i+=1)
  {
    Serial.print("2 * ");
    Serial.print(i);
    Serial.print(" = ");
    Serial.println(2*i);
  }
  delay(50000);
}
