#include<Wire.h>
#include<Adafruit_GFX.h>
#include<Adafruit_SSD1306.h>
#define OLED_RESET-1 
Adafruit_SSD1306 OLED(OLED_RESET);

//Button setup
int button[2] = {12,11};
int buzzer = 3 ;

int ball_speed = 3;

#if (SSD1306_LCDHEIGHT!= 32)
#error("Height incorrect,please fix Adafruit_SSD1306.h!");
#endif



int ball_x  , ball_y ;
int pad1_length , pad2_length ;
int cpu_score = 0 , player_score = 0;

int pad1x ,pad1y ,pad2x, pad2y , pad1_center = 3, pad2_center = 6;
int botstate ;
int ball_direction_x ;
int ball_direction_y ;

void player_win()
{
  OLED.clearDisplay();
  OLED.setTextColor(WHITE);
  OLED.setCursor(35,16);
  OLED.setTextSize(1.9);
  OLED.println("PLAYER WIN!");
  OLED.display();
  delay(3000);
}

void computer_win()
{
  OLED.clearDisplay();
  OLED.setTextColor(WHITE);
  OLED.setCursor(30,16);
  OLED.setTextSize(1.9);
  OLED.println("COMPUTER WIN!");
  OLED.display();
  delay(3000);
}


void show_score (int cpu_score , int player_score)
{
  OLED.clearDisplay();
  OLED.setTextColor(WHITE);
  OLED.setCursor(55,2);
  OLED.setTextSize(1);
  OLED.println("SCORE");
  OLED.setCursor(10,10);
  OLED.println("Player : ");
  OLED.setCursor(70,10);
  OLED.println(player_score);
  OLED.setCursor(10,20);
  OLED.println("COMPUTER : ");
  OLED.setCursor(70,20);
  OLED.println(cpu_score);
  OLED.display();
  delay(1000);
}

void paddle1_display()
{
  OLED.drawFastVLine(pad1x,pad1y,pad1_length,WHITE);
}

void paddle2_display()
{
  OLED.drawFastVLine(pad2x,pad2y,pad2_length,WHITE);
}

void ball_display ()
{
  OLED.drawPixel(ball_x,ball_y,WHITE);
}

void setup()
{
  Serial.begin(115200);
  randomSeed(analogRead(A0));
  ball_x = random(50,70) ;  ball_y = random(6,25);   pad1_length = 10 , pad2_length = 12;
  pad1x = 12 , pad1y = 13  ;   pad2x = 114 ; pad2y = 13;
  botstate = random(0,2);
  for(int i = 0;i<2;i++)
  {
    pinMode(button[i],INPUT);
  }
  OLED.begin(SSD1306_SWITCHCAPVCC,0x3C);
  OLED.clearDisplay();
  ball_direction_x =  random(0,2) ; // 0 for decrease , 1 for increase
  ball_direction_y =  random(0,2) ; // 0 for decrease , 1 for increase
  OLED.display();  
}

void loop()
{
  //Setup Display
  OLED.clearDisplay();
  OLED.drawRect(0,0,128,32,WHITE);
  ball_display();
  paddle1_display();
  paddle2_display();
  OLED.display();

  //Player button pressed
  for(int i = 0 ; i<2 ;i++)
  {
    int readbutton = digitalRead(button[i]);    
    if(readbutton == 1)  
    {
      if(i == 0)
      {
        if(pad1y>1)
          pad1y -= 2 ;         
      }
      if(i == 1)
      {
        if(pad1y<24)
          pad1y += 2 ;         
      }
    }
  }
  
  //Bot move left right automatic
  if(botstate == 1)
  {
      if(pad2y<18)
        pad2y += random(1,4) ;
      else
      {
        botstate = 0;   
      }
  }
  else
  {
    if(pad2y>1)
      pad2y -= random(1,4) ;
    else
    {
      botstate = 1;
    }
  }      


  //Ball bounce
  if(ball_direction_x == 0 && ball_direction_y == 0)  // x decrease y decrease 
  {
    if(ball_x>1 && ball_y>1)
    {
      ball_x -= ball_speed;
      ball_y -= ball_speed;
    }
    if(ball_x <= 1)
    {
      ball_direction_x = 1;
      ball_x = 1;
    }
    if(ball_y <= 1)
    {
      ball_direction_y = 1;
      ball_y = 1;
      tone(buzzer , 500 , 300 );
    }
  }
  else if(ball_direction_x == 0 && ball_direction_y == 1) // x decrease y increase
  {
    if(ball_x>1 && ball_y<30)
    {
      ball_x -= ball_speed;
      ball_y += ball_speed;
    }
    if(ball_x <= 1)
    {
      ball_direction_x = 1;
    }
    if(ball_y >= 30)
    {
      ball_direction_y = 0;
      ball_y = 30;
      tone(buzzer , 500 , 300 );
    }
  }
  else if(ball_direction_x == 1 && ball_direction_y == 0) // x increase y decrease
  {
    if(ball_x<126 && ball_y>1)
    {
      ball_x += ball_speed;
      ball_y -= ball_speed;
    }
    if(ball_x >= 126)
    {
      ball_direction_x = 0;
    }
    if(ball_y <= 1)
    {
      ball_direction_y = 1;
      ball_y = 1 ;
      tone(buzzer , 500 , 300 );
    }
  }
  else if(ball_direction_x == 1 && ball_direction_y == 1) // x increase y increase
  {
    if(ball_x<126 && ball_y<30)
    {
      ball_x += ball_speed;
      ball_y += ball_speed;
    }
    if(ball_x >= 126)
    {
      ball_direction_x = 0;
    }
    if(ball_y >= 30)
    {
      ball_direction_y = 0;
      ball_y = 30;
      tone(buzzer , 500 , 300 );
    }
  }

  //Check Score state
  if(ball_x < 10)
  {
    cpu_score++ ;
    tone(buzzer , 200 , 1000 );
    show_score(cpu_score,player_score);
    setup();
  }
  else if(ball_x > 116)
  {
    player_score++;
    tone(buzzer , 200 , 1000 );
    show_score(cpu_score,player_score);
    setup();
  }

  
  //Check between pad and ball
  if(ball_x <= pad1x && ball_y >= pad1y && ball_y <= (pad1y + pad1_length) && ball_direction_x == 0)
  {
      ball_direction_x = 1;
      ball_x = pad1x + 1;
      tone(buzzer , 1500 , 300 );
      
  }
  if(ball_x >= pad2x && ball_y >= pad2y && ball_y <= (pad2y + pad2_length) && ball_direction_x == 1)
  {
      ball_direction_x = 0;
      ball_x = pad2x - 1;
      tone(buzzer , 1500 , 300 );
  }

  //Check GameOver state
  if(player_score == 5)
  {
    tone(buzzer , 1500 , 500 );
    tone(buzzer , 3000 , 1000 );
    player_win();
    player_score=0;
    cpu_score=0;
    setup();
  }
  else if (cpu_score == 5)
  {
    tone(buzzer , 1500 , 500 );
    tone(buzzer , 3000 , 1000 );
    computer_win();
    cpu_score=0;
    player_score=0;
    setup();
  }
}
