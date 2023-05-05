
int button[] = {12,11,10}; 
              //12(R),11(Y),10(G)
int LED[] = {4,3,2}; 
           //4(R),3(Y),2(G)
// button 12 = PD button 12 = PU button 10 = IPU

int  timeR = 0 , timeG = 0, timeY = 0 ,swY = 0 ;

void setup()
{
  Serial.begin(9600);
  for(int i=0 ; i<=2 ;i+=1)
  {
    pinMode(LED[i],OUTPUT);
    pinMode(button[i],INPUT);
  }
  pinMode(button[2],INPUT_PULLUP);
}
void loop()
{
  int timePG = millis(); //Program_start (ตัววิ่ง)
   Red(timePG);
   Green(timePG);
   Yellow(timePG);
   delay(50);
}


  void Red(int timePG) // กดแดงติด 3 วิ (PULLDOWN) 
{
   if ((digitalRead(button[0]) == 1 )) //ติด
  {
    digitalWrite(LED[0], !digitalRead(LED[0])); 
    timeR = millis(); 
    delay(200);   
  } 
  else if (timePG - timeR > 3000) //ดับ
  {
     digitalWrite(LED[0], 0);
     timeR =0 ;
  }
}

  void Green(int timePG) // กดเขียวติด 3 วิ (PULLUP) 
{
  if (((digitalRead(button[2])) == 0 && (digitalRead(LED[0]) == 0))) //เขียวจะติดได้3วิเมื่อแดงดับ
  {
    digitalWrite(LED[2], !digitalRead(LED[2]) );
    timeG = millis();
    delay(200);
  }
  else if (timePG - timeG > 3000) //ดับ
  {
    digitalWrite(LED[2], 0);
    timeG = 0;
  }
}

void Yellow(int timePG)
{
  if ((digitalRead(button[1]) == 0) && (digitalRead(LED[0]) == 0) && (digitalRead(LED[2]) == 0)) //เหลืองติดกระพริบ 2ครั้ง ใน 2 วิ
  {
    digitalWrite(LED[1], 1);
    swY = millis();
    timeY = millis();
    delay(200);
    
  }
  else if( (timePG - timeY < 2000) && (timeY !=0) )
  {
    if( timePG - swY > 500)
    {
      digitalWrite(LED[1], ! digitalRead(LED[1]));
      swY = millis();
      
     }
  }
  else if (timePG - timeY > 2000 && (timeY !=0))
  {
     digitalWrite(LED[1], 0);
     timeY = 0;
   }
     
    
    
    
  
}
