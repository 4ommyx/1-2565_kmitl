int led1 = 7 ;
int led2 = 8 ;
int led3 = 9 ;
int sw = 3;
volatile int push = led1;
void setup() 
{
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(sw,INPUT);
  attachInterrupt(1,led,FALLING);
}
void loop() 
{
    for(int i = 0 ; i <   255 ; i+=1)
    {
      analogWrite(push,i); 
      delay(5); 
    }
    
}
void led()
  { 
    if(push == led1)
    {
      analogWrite(led1,0);
      push = led2;
     }
    else if(push == led2)
    {
      analogWrite(led2,0);
      push = led3;
    }
    else if(push == led3)
    {
      analogWrite(led3,0);
      push = led1;
    }
 }
