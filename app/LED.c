#include "LED.h"
#include "Times.h"

void turnOffLED(int LED)
{
	if (LED == LED3)
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_RESET);
	else if (LED == LED4)
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_14, GPIO_PIN_RESET);
	else if (LED == LED5)
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET);
	else
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_SET);
}

void turnOnLED(int LED)
{
	if (LED == LED3)
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_SET);
	else if (LED == LED4)
		HAL_GPIO_WritePin(GPIOG, GPIO_PIN_14, GPIO_PIN_SET);
	else if (LED == LED5)
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET);
	else
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_5, GPIO_PIN_RESET); //LED6 active low
}

int readUserInput()
{
	GPIO_PinState UserInput = 0;
	UserInput = HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_0);

	if (UserInput == 1)
		return 1 ;
	else
		return 0 ;
}

