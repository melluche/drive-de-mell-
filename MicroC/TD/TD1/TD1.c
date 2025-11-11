#include <stm32l4xx_hal.h>
#include "telerupteur.h"


void allume(){
	static int status_led=0;
	static int compteur=0;

	while(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_13)==1){
		}
	status_led=1-status_led;
	compteur++;


	printf("Compteur = %d, led=%d \n\r",compteur,status_led);
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,status_led);
	while(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_13)==0){
		}

}
