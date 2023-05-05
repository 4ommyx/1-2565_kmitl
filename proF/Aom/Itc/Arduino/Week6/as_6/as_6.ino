int segmentpin[8] = {13,12,11,10,9,8,7} ;    // a b c d e f g //
int num[10] = {7789,B11111001,B10100100,B10110000,B10011001,B10010010,B10000010,B11011000,B10000000,B10010000}; //number
int sym[4] = {7789,B11000000,B11000111,B11000010}; //symbol
int button[2] = {6,5};
int reading[2] ;
int lastButtonState[2] = {1, 1};
int buttonState[2];
int number = 0 ; //setSymbol
int symbol = 1 ; //setNumber
int debounceDelay = 50;
int lastDebounceTime[2];
int randomNumber ; 
// common Anode = 0 For high
//  num1 = B11111001  // eq = B11000000 เท่ากับ
//  num2 = B10100100  // L  = B11000111 น้อยกว่า
//  num3 = B11110000  // G  = B11000010 มากกว่า
//  num4 = B10011001
//  num5 = B10010010
//  num6 = B10000010
//  num7 = B11011000
//  num8 = B10000000
//  num9 = B10010000
void setup() 
{
  Serial.begin(9600);
  
  for(int i = 0 ; i <8 ;i++)
    {
      pinMode(segmentpin[i],OUTPUT); // 8 pin
    }
    pinMode(button[0],INPUT_PULLUP);
    pinMode(button[1],INPUT_PULLUP);
    randomSeed(analogRead(A0));
    randomNumber = random(1,10); //realmax = max-1
}
void loop()
{
  handle_start_button();
  handle_guess_button();
  
}
int debounce(int i)
{
  int isChange = 0;
  reading[i] = digitalRead(button[i]);
  if (reading[i] != lastButtonState[i])
  {
    lastDebounceTime[i] = millis();
  }
  if ((millis() - lastButtonState[i]) > debounceDelay)
  {
    if (reading[i] != buttonState[i])
    {
      buttonState[i] = reading[i];
      isChange = 1;
    }
  }
  lastButtonState[i] = reading[i];
  return isChange;
}
void handle_start_button() //กดปุ่มตัวเลข
{  
    
     if(debounce(0))
      {
        if(0 == digitalRead(button[0]))
        {
          number +=1 ; 
          if(number == 10)
          {
           number = 1 ;   
          }
        numberRun(number);
        delay(250);    
        }        
      }
}
void numberRun(int number) //แสดงผลตัวเลข
{
  for(int pt = 0 ; pt <8 ; pt ++)  // pt : position of bit 
         {
          boolean isBitSet = bitRead(num[number],pt);
          digitalWrite(segmentpin[pt],isBitSet);            
         }
}
void handle_guess_button() //กดปุ่มสัญลักษณ์
{
  if (debounce(1))
  {
    if (0 == digitalRead(button[1]))
    {
      if (number == randomNumber)
      {
        delay(500);
        numberCheck(1);
        randomNumber = random(1,10); //
        Serial.println(randomNumber);
      }
      else if (number < randomNumber)
      {
        delay(500);
        numberCheck(2);
      }
      else if (number > randomNumber)
      {
        delay(500);
        numberCheck(3);
      }
    }
  }
}
void numberCheck(int symbol) //แสดงผลสัญลักษณ์
{
  for(int pt = 0 ; pt <8 ; pt ++)  // pt : position of bit 
         {
          boolean isBitSet = bitRead(sym[symbol],pt);
          digitalWrite(segmentpin[pt],isBitSet);      
         }
}    
