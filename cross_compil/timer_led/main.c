#include "led.h"
#include "timer.h"

int main() 
{
  //chenillard();
  while(1) {
	 switchOnOff((unsigned short)1, OFF);
	 //wait100ms();
	 wait(1000);
	 switchOnOff((unsigned short)1, ON);
	 //wait100ms();
	 wait(1000);
  }

  return 0; //EXIT_SUCCESS
}
