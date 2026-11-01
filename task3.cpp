#include <Arduino.h>
#include "task3.h"


void setup_task3(){
  DDRB &= ~(1<<DDB1) ; //pin intrare buton
  PORTB |= (1<<PB1); // activeaza rezistenta de pull up
  DDRB |= (1 <<DDB0);//pin iesire led
  PORTB &= ~(1<<PB0); //led stins initial

  PCICR |= (1<<PCIE0);//activare intrerupere pe piniB
  PCMSK0 |= (1<<PCINT1); // activare intrerupere pe pinul PB1

  sei(); //activare intreruperi globale
}

ISR(PCINT0_vect)
{
  _NOP();//pentru sincronizare
  bool stare_buton = PINB & (1<<PB1); // 1 neapasat , 0 apasat
  if(stare_buton == false)
  {
    while(stare_buton);
    _delay_ms(25);
    PORTB ^= (1<<PB0);
  }
}