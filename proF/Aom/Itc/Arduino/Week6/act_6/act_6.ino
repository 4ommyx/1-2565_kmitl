int led = 13 ;
int senserPin = A0 ; //1
int ldr_a = A1 ; 
int ldr_d = 12 ;     //2
int segmentpin[8] = {13,12,11,10,9,8,7,6} ;    // a b c d e f g //
int num[9] = {B11111001,B10100100,B10110000,B10011001,B10010010,B10000010,B11011000,B10000000,B10010000} ;
// common Anode = 0 For high
 // num1 = B11111001
 // num2 = B10100100
 // num3 = B11110000
 // num4 = B10011001
 // num5 = B10010010
 // num6 = B10000010
 // num7 = B11011000
 // num8 = B10000000
 // num9 = B10010000


void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  for(int i = 0 ; i <8 ;i++)
    {
      pinMode(segmentpin[i],OUTPUT); // 8 pin
    }
  }

void loop() {
  //ac6_1();
  //ac6_2();
  //ac6_3();
}
  
//  void ac6_1()
//  {
//  int set = analogRead(senserPin) ;
//  Serial.println(set);
//  digitalWrite(led,0);
//  delay(set);
//  digitalWrite(led,1);
//  delay(set);  
//  }
//  void ac6_2()
//  {
//   int readLdr_a = analogRead(ldr_a);
//   int readLdr_d = digitalRead(ldr_d);
//   Serial.print(readLdr_a);
//   Serial.print("||");
//   Serial.println(readLdr_d);
//   delay(500);
//   
//   }
//   void ac6_3()
//   { 
//      for(int j = 0 ; j < 9 ; j++) // j : j+1 = num
//      {
//        for(int pt = 0 ; pt <8 ; pt ++)  // pt : position of bit 
//         {
//          boolean isBitSet = bitRead(num[j],pt);
//          digitalWrite(segmentpin[pt],isBitSet);      
//      
//         }
//       delay(100);
//      }
//   }
