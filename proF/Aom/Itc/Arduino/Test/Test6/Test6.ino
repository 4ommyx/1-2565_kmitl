int switch1 = 13;
int num1; 
int LED_1 = 7;
int buttonset = 1;
void setup() 
{


  Serial.begin(9600);                    // diditalwrite คู่กับ output
  pinMode(switch1,INPUT_PULLUP);         //digitalread คู่กับ input
  pinMode(LED_1,OUTPUT);                 //สวิซจะทำวานได้ต้องต่อให้ครบวงจร
                                         //input แบบปกติ ใส่ R ด้วย ต่อให้ครบวงจร (emf V0 pin R)
                                         //pull up = 1 กด = 0 (จะ up down อยู่ที่pinว่าอยู่ที่ขั้วไหน
}                                        // input_pullup ไม่ต้องต่อ  R ต่อแค่pinกับ V0 (Func พิเศษ ของarduino)
void loop() {
  
  int num1 = digitalRead(switch1);
    if(num1==0)
    {
      
    digitalWrite(LED_1,0);
        
     }
      
     else   
     {
     digitalWrite(LED_1,1);
     
      
     }
     Serial.println(num1);

     delay(100);
  }
 

  
