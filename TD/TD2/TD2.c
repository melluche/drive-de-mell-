
#include <stdio.h>
#include <stm32l4xx_hal.h>
#include "TD2.h"
#define ARRAY_SIZE 3

void quizz( void){
	int interr = HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_13);
	if ( interr==0){
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,1);
		printf( "LIGHT ON \n \r ");
		HAL_Delay(1500);
			}
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,0);
	printf( " LIGHT OFF \n \r ");
}


void setup2(void){

	/*
int ceci_est_une_variable = 100;
printf("Variable selon diff´erents formats : %d, %x, %c \n\r",ceci_est_une_variable,ceci_est_une_variable,ceci_est_une_variable);
ceci_est_une_variable++;
printf("Apr`es modification : %d, %x, %c \n\r",ceci_est_une_variable,ceci_est_une_variable,ceci_est_une_variable);



uint8_t c;

for(c=0; c<=254; c++){

printf("c = %d %x %c \n\r", c, c, c);
}
printf("c = %d %x %c \n\r", c, c, c);
c++;
printf("c = %d %x %c \n\r", c, c, c);
*/

}
int static globale = 100;

void fonction(int parametre){
	int locale = 5;
	locale++;
	globale++;
	parametre++;
	printf("*** Interieur de la fonction *** \n\r Valeur de locale : %d \t de globale : %d \t de parametre : %d\n\r", locale, globale, parametre);
	}



void setup3(void){
	int locale = 10;
	int parametre = 20;
	printf("*** Setup avant appel de fonction ***\n\rValeur de locale : %d\t de globale : %d \t de parametre : %d \n\r",locale, globale, parametre);

	fonction(parametre);
	printf("*** Setup apres appel de fonction ***\n\rValeur de locale : %d\t de globale : %d \t de parametre : %d \n\r",locale, globale, parametre);
	}



void stupid_function(int stupid_variable){
	stupid_variable++;
}

void not_so_stupid_function( int* ptr ){
	*ptr= *ptr + 1;

}

void another_function(void){
	int x = 0;
	int* ptr= &x;
	not_so_stupid_function( ptr);
	printf("Valeur de x : %d \r \n ", x);
}





void fillArray( int* array, int size){
	static int i=0;

	int heure_1= 0;
	int heure_2=0;

	while ( i<size){

		while(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_13)==1) {

		}
		heure_1=HAL_GetTick();


		while(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_13)==0){

		}
		heure_2=HAL_GetTick();


		array[i]=heure_2- heure_1;

		i++;


	}

}


void displayArray(int array[ARRAY_SIZE]){
	int i;
	for (i = 0; i < ARRAY_SIZE; i++){
		printf("array[%d] = %d\n\r", i, array[i]);
	}
}



int getMeanValue(int* array, int size){
	int cpt=0;


	for (int i=0 ; i<size; i++){
		cpt+=array[i];


	}
	int m = cpt / size;

	printf(" %d \n \r", m);
	return  0;
}






void loop5(void){
	int array[ARRAY_SIZE] = {0};
	fillArray( array, ARRAY_SIZE);
	displayArray( array);
	getMeanValue(array,ARRAY_SIZE);
}

