#define LED1 13
#define LED2 12
#define LED3 11

void setup() {
  
  
  }

void loop() {
  pinMode(LED1,OUTPUT); //1
  pinMode(LED2,OUTPUT);
  pinMode(LED3,INPUT);
  digitalWrite(LED1,HIGH);
  digitalWrite(LED2,LOW);
  delay(500);
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,HIGH);
  delay(500);

  pinMode(LED1,OUTPUT); //2
  pinMode(LED2,INPUT);
  pinMode(LED3,OUTPUT);
  digitalWrite(LED1,HIGH);
  digitalWrite(LED3,LOW);
  delay(500);
  digitalWrite(LED1,LOW);
  digitalWrite(LED3,HIGH);
  delay(500);
  
  pinMode(LED1,INPUT); //3
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  digitalWrite(LED2,HIGH);
  digitalWrite(LED3,LOW);
  delay(500);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,HIGH);
  delay(500);
  
  digitalWrite(LED2,LOW); //4
  digitalWrite(LED3,HIGH);
  delay(500);
  digitalWrite(LED2,HIGH);
  digitalWrite(LED3,LOW);
  delay(500);

  pinMode(LED1,OUTPUT); //5
  pinMode(LED2,INPUT);
  pinMode(LED3,OUTPUT);
  digitalWrite(LED1,LOW);
  digitalWrite(LED3,HIGH);
  delay(500);
  digitalWrite(LED1,HIGH);
  digitalWrite(LED3,LOW);
  delay(500);
  
  pinMode(LED1,OUTPUT); //6
  pinMode(LED2,OUTPUT);
  pinMode(LED3,INPUT);
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,HIGH);
  delay(500);
  digitalWrite(LED1,HIGH);
  digitalWrite(LED2,LOW);
  delay(500);
  
  

}
