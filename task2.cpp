#include <Arduino.h>
#include "task2.h"

bool stare_anterioara_buton = true;

void setup_task2()
{
  DDRD &= ~(1<<DDD5) ;
  PORTD |= (1<<PD5); // activeaza rezistenta de pull up
  DDRD |= ((1 <<DDD6) | (1<<DDD7));
  PORTD |= (1<<PD6);
  PORTD &= ~(1<<PD7);
}

void task_2(){
  _NOP();//pentru sincronizare
  bool stare_buton = PIND & (1<<PD5); // 1 neapasat , 0 apasat
  
  if(stare_buton == false && stare_anterioara_buton== true)
  {
    if(PORTD & (1<<PD6))
    {
      PORTD &= ~(1<<PD6);
      PORTD |= (1<<PD7);
    }
    else{
      PORTD |= (1<<PD6);
      PORTD &= ~(1<<PD7);
    } 
  }
  stare_anterioara_buton = stare_buton;
}