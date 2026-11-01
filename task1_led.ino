#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "task4.h"

void nothing_i(unsigned long j)
{
  unsigned long i=0;
  while(i<j)
  {
    _NOP();
    i++;
  }
}

void setup() {
  // put your setup code here, to run once:
  setup_task1();
  setup_task2();
  setup_task3();
  setup_task4();
  Serial.begin(9600);
  nothing_i(2000000);
}

void loop() {
  // put your main code here, to run repeatedly:
  //task_1();
  task_2();
}
