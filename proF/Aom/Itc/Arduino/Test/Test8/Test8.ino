int vr_pin = A0 ; // Analog_pin พวก pin A 
int led = 9 ;

void setup() {
  pinMode(vr_pin,INPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  int vr = analogRead(vr_pin);
  int vr_map = map(vr,0,255,0,5); //กำหนวดช่วง
  analogWrite(led,vr_map);
  Serial.println(vr_map);
  delay (50);
}
