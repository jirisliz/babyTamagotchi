#include "baby.h"

#define PIN_BTN0  2  // feed 
#define PIN_BTN1  3  // play
// both -> clean

CBaby *cBaby;

void setup()
{
  // Set up buttons
  pinMode(PIN_BTN0, INPUT);
  pinMode(PIN_BTN1, INPUT);
  
  // Set up baby
  cBaby = new CBaby();
}

unsigned int countDelay = 0;

int btn1 = 0, btn2 = 0;
int st1 = 0, st2 = 0, st3 = 0;

void loop(void)
{
  while (true)
  {       
    countDelay++;
    if(countDelay > 100)
    {
      countDelay = 0;
      cBaby->updateBaby();  
    }

    btn1 = digitalRead(PIN_BTN0); // feed 
    btn2 = digitalRead(PIN_BTN1); // play
    
    if(btn1 == LOW && btn2 == LOW)
    {
      st1 = HIGH;
    }
    if(btn1 == HIGH && btn2 == HIGH && st1 == HIGH)
    {
      st1 = LOW;
      cBaby->babyClean();
    }

    if(btn1 == HIGH && btn2 == LOW)
    {
      st2 = HIGH;
    }
    if(btn1 == LOW && btn2 == HIGH && st2 == HIGH)
    {
      st2 = LOW;
      cBaby->babyPlay();
    }

    if(btn1 == LOW && btn2 == HIGH)
    {
      st3 = HIGH;
    }
    if(btn1 == HIGH && btn2 == LOW && st3 == HIGH)
    {
      st3 = LOW;
      cBaby->babyFeed();
    }
    
    delay(5);
  }
}
