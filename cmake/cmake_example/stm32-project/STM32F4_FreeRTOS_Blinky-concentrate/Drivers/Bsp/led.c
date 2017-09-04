#include "led.h"



void LEDInit(void)                                                                                                                                                 
{
GPIO_InitTypeDef GPIO_InitStructure;
/* Enable the PI1 clock */
__GPIOF_CLK_ENABLE();
GPIO_InitStructure.Pin = GPIO_PIN_9|GPIO_PIN_10;
GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
GPIO_InitStructure.Pull = GPIO_NOPULL;
HAL_GPIO_Init(GPIOF, &GPIO_InitStructure);
/* Set the PI1 default level to low */
HAL_GPIO_WritePin(GPIOF, GPIO_PIN_9|GPIO_PIN_10, GPIO_PIN_RESET);
}

