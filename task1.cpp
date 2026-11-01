#include <Arduino.h>
#include "task1.h"

unsigned long time = millis();

void setup_task1()
{
  DDRD |= (1<<DDD2) | (1<<DDD3) | (1<<DDD4);
  PORTD &= ~((1<<PD2) | (1<<PD3) | (1<<PD4));
}

void task_1()
{

  if(millis()-time > 1000)
  {
    if ((PORTD & (1<<PD2)) && (PORTD & (1<<PD3)) && (PORTD & (1<<PD4)))
    {
      PORTD &= ~((1<<PD2) | (1<<PD3) | (1<<PD4));
    }
     else if ((PORTD & (1<<PD2)) && (PORTD & (1<<PD3)))
    {
        PORTD |= (1<<PD2) | (1<<PD3) | (1<<PD4);
    }
    else if (PORTD & (1<<PD2))
    {
      PORTD &= ~((1<<PD4)); 
      PORTD |= (1<<PD2) | (1<<PD3);
    }
    else
    {
      PORTD &= ~((1<<PD3) | (1<<PD4));
      PORTD |= (1<<PD2);
    } 
    time = millis();     
  }
}
