int point = 120 ;
void setup() {
  Serial.begin(9600);

}

void loop() {
  if( (point>=80)|| (point>=100))
  {
  Serial.println("A");
  }
  else
  {
    Serial.println("No");  
  }
  delay(500);
 }
