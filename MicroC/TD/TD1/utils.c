/*
 * utils.c
 *
 *  Created on: Sep 17, 2025
 *      Author: 33658
 */

#include <stm32l4xx_hal.h>
#include "utils.h"


void loop3(){
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
	HAL_Delay(250);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_SET);
	HAL_Delay(250);

 }

void setup(){

  }
