int mortor = 3;
void setup() {
  pinMode(mortor,OUTPUT);

}

void loop() {
  for(int i=0 ; i<=255 ; i+=1)
  {
  analogWrite(mortor,0);
  }
  delay(1000);
}
