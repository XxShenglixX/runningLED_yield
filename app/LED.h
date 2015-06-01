#ifndef LED_H
#define LED_H

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_gpio.h"

enum {
				LED3 = 0,
				LED4,
				LED5,
				LED6
};

typedef enum {
				START,
				LED_OFF,
				LED_ON,
				CHECK_BUTTON,
				BUTTON_NOT_PRESSED,
				BUTTON_PRESSED
}State;

void turnOffLED(int LED);
void turnOnLED(int LED);
int readUserInput();

#endif // LED_H
