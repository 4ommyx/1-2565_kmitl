 int LED_R = 9 ;
int LED_Y = 8 ;
int LED_G = 7 ;


void setup() {
  pinMode(LED_R,OUTPUT);
  pinMode(LED_Y,OUTPUT);  //pinMode รับ-ส่งค่าจากช่องpinต่างๆ
  pinMode(LED_G,OUTPUT);

}

void loop() {
  digitalWrite(LED_R,1);
  digitalWrite(LED_Y,0);  //Write=แสดงค่า Read=รับค่า
  digitalWrite(LED_G,0); //ทุก pin เป็นช่อง digital ทุกช่อง
  delay(1000);

  digitalWrite(LED_R,0);
  digitalWrite(LED_Y,1);  //Write=แสดงค่า Read=รับค่า
  digitalWrite(LED_G,0);  //ทุก pin เป็นช่อง digital ทุกช่อง
  delay(1000);

  digitalWrite(LED_R,0);
  digitalWrite(LED_Y,0);  //Write=แสดงค่า Read=รับค่า
  digitalWrite(LED_G,1);  //ทุก pin เป็นช่อง digital ทุกช่อง
  delay(1000);

  

}
