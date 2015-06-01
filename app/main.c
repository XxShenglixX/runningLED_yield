#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"
#include "configuration.h"
#include "Times.h"
#include "LED.h"

typedef struct
{
	State state ;
}TaskBlock ;

#define initTaskBlock(x) 	(x)->state = 0 ;
#define yield(x) 			(x)->state = __LINE__ ; return 1 ; case __LINE__ : ;
#define startTask(x)  		switch((x)->state) {case 0:
#define endTask(x)   		break; }

#define _100ms 100
#define _120ms 120
#define _200ms 200
#define _500ms 500
#define _1000ms 1000
#define _2000ms 2000

int blinkLED(TaskBlock *tb ,int Time_LED, int LED_no)
{
	startTask(tb);
		turnOnLED(LED_no);
		while(!checkTime(Time_LED,LED_no)){
						yield(tb);
					}
		turnOffLED(LED_no);
		while(!checkTime(Time_LED,LED_no)){
							yield(tb);
						}
		tb->state = 0 ; //restart
		endTask(tb);

		return 1 ;
}

int inverseBlinkLED(TaskBlock *tb ,int Time_LED, int LED_no)
{
	startTask(tb);
	turnOffLED(LED_no);
	while(!checkTime(Time_LED,LED_no)){
					yield(tb);
				}
	turnOnLED(LED_no);
	while(!checkTime(Time_LED,LED_no)){
						yield(tb);
					}
	tb->state = 0 ; //restart
	endTask(tb);

	return 1 ;
}

int runningLED(TaskBlock *tb,int Time_LED)
{

	startTask(tb);

	turnOnLED(LED3);
	while(!checkTime(Time_LED,LED3)){
					yield(tb);
				}
	turnOffLED(LED3);
	while(!checkTime(Time_LED,LED3)){
					yield(tb);
				}

	turnOnLED(LED4);
	while(!checkTime(Time_LED,LED3)){
					yield(tb);
				}
	turnOffLED(LED4);
	while(!checkTime(Time_LED,LED3)){
					yield(tb);
				}

	turnOnLED(LED5);
	while(!checkTime(Time_LED,LED3)){
					yield(tb);
				}
	turnOffLED(LED5);
	while(!checkTime(Time_LED,LED3)){
					yield(tb);
				}

	turnOnLED(LED6);
	while(!checkTime(Time_LED,LED3)){
					yield(tb);
				}
	turnOffLED(LED6);
	while(!checkTime(Time_LED,LED3)){
					yield(tb);
				}
	tb->state = 0 ; //restart
	endTask(tb);

	return 1 ;
}


void blink5times(TaskBlock *tb)
{
	static int i = 0 ;

	startTask(tb);
	while(!readUserInput()){
		yield(tb);
	}

	for ( i = 0 ; i < 5 ; i ++)
	{
		turnOnLED(LED3);

		while(!checkTime(100,5)){
			yield(tb);
		}

		turnOffLED(LED3);
		while(!checkTime(100,5)){
			yield(tb);
		}

	}

	while(readUserInput()){
			yield(tb);
		}

	tb->state = 0 ;
	endTask(tb);

}

void clearLED3_LED4()
{
	turnOffLED(LED3);
	turnOffLED(LED4);
}


int main(void)
{
	int Time_LED5 = _1000ms ,
		Time_LED6 = _1000ms ,
		Time_LED = _100ms;

	TaskBlock tb_LED6,tb_LED5, tb,tb1 ;

	initTaskBlock(&tb);
	initTaskBlock(&tb1);
	initTaskBlock(&tb_LED6);
	initTaskBlock(&tb_LED5);

	initLED();
	configButton();

	while(1)
	{
		if (readUserInput())
			runningLED(&tb,Time_LED);
		else
		{
			clearLED3_LED4();
			//blink5times(&tb1);
			blinkLED(&tb_LED6,Time_LED6,LED6);
			inverseBlinkLED(&tb_LED5,Time_LED5,LED5);
		}
		updateCurrentTime();
	}


}




