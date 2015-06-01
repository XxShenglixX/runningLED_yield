#include "Times.h"

uint32_t currentTime = 0 ;

void updateCurrentTime()
{
	static uint32_t counter = 0 ;

	if (counter++ >= 100)
	{
		counter = 0 ;
		currentTime ++ ;
	}
}

int checkTime(int Time_LED,int LED_no)
{
	static uint32_t previousTime[5] = {0} ;

	if(currentTime - previousTime[LED_no] >= Time_LED)
	{
		previousTime[LED_no] = currentTime ;
		return 1;
	}
	else
		return 0 ;

}
