#include "led.h"
#include "timer.h"

int main() 
{
  //chenillard();
  while(1) {
	 switchOnOff((unsigned short)1, ON);
	 wait100ms();
	 switchOnOff((unsigned short)1, OFF);
	 wait100ms();
  }

  return 0; //EXIT_SUCCESS
}
