int PULLUP = 1 ;
int IN_PULLUP = 1 ;
int PULLDOWN = 0 ;

int sw1 = 13 ;  //sw1 = PULLUP
int LED1 = 9 ;
int sw2 = 12 ;  //sw2 = IN_PULLUP
int LED2 = 8 ;
int sw3 = 10 ;  //sw3 = PULLDOWN
int LED3 = 7 ;


void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(sw1,INPUT);
  pinMode(LED1,OUTPUT);
  pinMode(sw2,INPUT_PULLUP);
  pinMode(LED2,OUTPUT);
  pinMode(sw3,INPUT);
  pinMode(LED3,OUTPUT);


}

void loop() {
  int num1 = digitalRead(sw1);
  int num2 = digitalRead(sw2);
  int num3 = digitalRead(sw3); //ER
  
  if(num1 == 0 )
  {
    delay(50);

      if(PULLUP == 1){
      
      digitalWrite(LED1,1);
      PULLUP = 0;
      delay(3000);
      }
      else
      {

       digitalWrite(LED1,0);
       PULLUP = 1;
       delay(200);
        
        
      }
       
      Serial.println(num1);
      

      
  }
    
    
    
  if(num2 == 0 )
    {
      delay(50);

      if(IN_PULLUP == 1){
      
      digitalWrite(LED2,1);
      IN_PULLUP = 0;
      delay(200);
      }
      else
      {

       digitalWrite(LED2,0);
       IN_PULLUP = 1;
       delay(200);
        
        
      }
       
      }    
    if(num3 == 1 )
    {
      delay(50);

      if(PULLDOWN == 0){
      
      digitalWrite(LED3,0);
      PULLDOWN = 1;
      delay(200);
      }
      else
      {

       digitalWrite(LED3,1);
       PULLDOWN = 0;
       delay(200);
        
        
      }
      

      
    
    

    } 
     

}
