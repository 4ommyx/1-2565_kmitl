int Led[]= {9,8,7};
int vr = A0;

void setup() {
  for(int i=0 ;i<=2 ; i+=1)
  {
   pinMode(Led[i],OUTPUT); 
   pinMode(vr,INPUT); 
  }
}

void loop() 
{
  int time1 = analogRead(vr);
  int time1_map = map(time1,0,255,0,255); //กำหนวดช่วง
  
  for(int i=0 ;i<=2 ; i+=1)
  {
   digitalWrite(Led[i],1);
   delay (time1_map); 
  }
  
  for(int i=2 ;i>=0 ; i-=1)
  {
   digitalWrite(Led[i],0); 
   delay (time1_map);
  }
  

}
