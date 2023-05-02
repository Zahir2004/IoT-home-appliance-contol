#include "ARDUINO.h"
#include "Lcd.h"
#define LCD_ADDRESS 0x20
#define LCD_ROWS 2
#define LCD_COLUMNS 16
#define BACKLIGHT 255
#define KEYPAD A0

Lcd mylcd;

void setup() {
  // put your setup code here, to run once:
 mylcd.begin(LCD_COLUMNS,LCD_ROWS,LCD_ADDRESS,BACKLIGHT);
 mylcd.clear();
 pinMode(KEYPAD,INPUT);
 
 for(int i=2;i<=9;i++)
 pinMode(i, OUTPUT);
}

void loop() 
{
  
  int r,i;
  char ch;
  int pr=0;
  r=analogRead(KEYPAD);
  if(pr!=r)
  {
    mylcd.clear();
    //mylcd.print(r);
    if(r==68)
    {
      mylcd.print("Welcome");
      delay(50);
      i=15;//On Button
      for(int a=2; a<=9; a++){
       digitalWrite(a, LOW);  
      }
    }
    else if(r==98)
    {
      i=1;
      mylcd.clear();
      digitalWrite(2, HIGH);
    }
    else if(r==90)
    {
      i=2;
      mylcd.clear();
      digitalWrite(3, HIGH);
    }
    else if(r==83)
    {
      i=3;
      mylcd.clear();
      digitalWrite(4, HIGH);
    }
    else if(r==180)
    {
      i=4;
      mylcd.clear();
      digitalWrite(5, HIGH);
    }
    else if(r==153)
    {
      i=5;
      mylcd.clear();
      digitalWrite(6, HIGH);
    }
    else if(r==133)
    {
      i=6;
      mylcd.clear();
      digitalWrite(7, HIGH);
    }
    else if(r==1023)
    {
      i=7;
      mylcd.clear();
      digitalWrite(8, HIGH);
    }
    else if(r==512)
    {
      i=8;
      mylcd.clear();
      digitalWrite(9, HIGH);
    }
    else if(r==341)
    {
      i=9;
      for(int a=2; a<=9; a++){
       digitalWrite(a, HIGH);  
      }
    }
    else if(r==64)
    {
      i=0;
      for(int a=2; a<=9; a++){
       digitalWrite(a, LOW);  
      }
    }
    else if(r==60)
    {
      i=11;//=
      mylcd.clear();
      mylcd.print("Pattern >> 2");
      //mylcd.print(i);
      for(int a=0; a<=5; a++){
      for(int j=2; j<=9; j++)
      {
         digitalWrite(j, HIGH);
         digitalWrite(j+1, HIGH);
         digitalWrite(j+2, HIGH);
         digitalWrite(j+3, HIGH);
         digitalWrite(j+4, HIGH);
         digitalWrite(j+5, HIGH);
         digitalWrite(j+6, HIGH);
         digitalWrite(j+7, HIGH);
         delay(5);
      } 
      for(int j=2; j<=9; j++)
      {
         digitalWrite(j, LOW);
         digitalWrite(j+1, LOW);
         digitalWrite(j+2, LOW);
         digitalWrite(j+3, LOW);
         digitalWrite(j+4, LOW);
         digitalWrite(j+5, LOW);
         digitalWrite(j+6, LOW);
         digitalWrite(j+7, LOW);
         delay(5);  
       }
      }
     }
    else if(r==57)
    {
      i=10;//+
      mylcd.clear();
      mylcd.print("Pattern >> 1");
      //mylcd.print(i);
      for(int a=0; a<=5; a++){
      for(int j=2; j<=9; j++)
      {
        digitalWrite(j, HIGH);
        delay(5);
      }
      for(int j=2; j<=9; j++)
      {
        digitalWrite(j, LOW);
        delay(5);  
      }
      }
    }
    else if(r==76)
    {
      i=12;//-
    }
    else if(r==118)
    {
      i=13;//*
    }
    else if(r==256)
    {
      i=14;//'/'
    }
    mylcd.clear();
    mylcd.selectLine(2);
    mylcd.clear();
    
    if(i>=0 && i<10){
    mylcd.print("LED:-");
    mylcd.print(i);
    }
    else if(i>11 && i!=15){
    mylcd.print("Enter valide");
    mylcd.selectLine(2);
    mylcd.print("LED no...");
    //delay(100);
    //mylcd.clear();
    }
    /*else if(i==11)
    mylcd.print("+");
    else if(i==12)
    mylcd.print("-");
    else if(i==13)
    mylcd.print("*");
    else if(i==14)
    mylcd.print("/");*/
    else if(i==15)
    mylcd.print("Choice:-");
    pr=r;
  }
}

 char readKeypad(int scancode)
 {
    if((scancode>=240)&&(scancode<=244))
    {
      return '1';
    }
    
 }
