int a=10 ; 
int b=3 ;

void setup() {
  Serial.begin(9600); //ค่าการรับส่งข้อมูล

}

void loop() {
  
  Serial.print("A = "); //printf
  Serial.println(a); //newline

  delay(1);
}
