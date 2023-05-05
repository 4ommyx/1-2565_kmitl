// Annaog มีหลายค่า ต่างจาก digital ที่มีเพียง2ค่า
// ขา analog ได้แก่ขาที่มีสัญลักษณ์ ตัวหนอน
int led = 9 ;
void setup() {
  pinMode(led,OUTPUT);

}

void loop() {
  analogWrite(led,255);
  delay(500);
  analogWrite(led,191);
  delay(500);
  analogWrite(led,127);
  delay(500);
  analogWrite(led,64);
  delay(500);
  analogWrite(led,0);
  delay(500);



}
