#include <Arduino.h>
#include "task4.h"

void setup_task4(){
    DDRD |= (1<<DDD2) | (1<<DDD3) | (1<<DDD4);
    PORTD &= ~((1<<PD2) | (1<<PD3) | (1<<PD4));
    unsigned char sreg;
    sreg= SREG;
    cli();
    TCCR1A=0;
    TCCR1B=0;
    TCNT1 = 0;
    OCR1A = 62499;//16000Hz/(64*4Hz)-1=62499
    TCCR1B |= (1<< WGM12); // CTC = clear time on compare match
    TCCR1B |= (1<<CS11) | (1<<CS10);// prescaler = 64 cs12=0, cs11=1, cs10=1
    TCCR1B &= ~(1<<CS12);
    TIMSK1 |= (1 << OCIE1A); //activare intrerupera de comparare cu ocr1a
    SREG=sreg;
    sei();
}

ISR(TIMER1_COMPA_vect)
{
  //Serial.println("hello");
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
}
