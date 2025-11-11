#include <stdio.h>
#include <stm32l4xx_hal.h>
#include "TD3.h"

#define ARRAY_SIZE_15 4000


// quizz



void displayArray_TD3(int array[ARRAY_SIZE_15]){
	int i;
	for (i = 0; i < ARRAY_SIZE_15; i++){
		printf("array[%d] = %d\n\r", i, array[i]);
	}
}



void fillArray_TD3( int* array, int size){
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






void caracArray( int array[ARRAY_SIZE2], int* pmin, int* pmax, float* moy){
	int cpt=0;

	for (int i=0; i< ARRAY_SIZE2; i++){
		cpt+= array[i];


		if (array[i]<*pmin){
			*pmin= array[i];
		}

		if ( array[i]> *pmax){
			*pmax = array[i];
		}



	}
	*moy= cpt/ ARRAY_SIZE2;

}


// tri par recherche du minimum


int getMinPosition( int* array, int* toBeIgnored, int size){
	int mini;

	for (int i=size-1; i>=0; i--){

		if ( toBeIgnored[i]==0 ){
			mini= i;
		}

	}

	for (int i=0; i<size; i++){
		if( array[i]<=array[mini] && toBeIgnored[i]==0){
				mini=i;
		}

	}
	return mini;

}





int array_test[ARRAY_SIZE_15]={0, 1, -3, 10, -1, 0, 0, 0, 0, 12, 1024, 10, 45, 6, 4};

int* sortArray(int * toSort, int *sorted, int size){
	int ignored[ARRAY_SIZE_15]={0};
	int index=0;
	int cpt=0;
	int i=0;


	while ( cpt< ARRAY_SIZE_15){
		index=getMinPosition(toSort, ignored, ARRAY_SIZE_15);
		ignored[index]=1;
		sorted[i]= toSort[index];
		i++;
		cpt++;

	}

	return sorted ;

}


int arrayTest2[ARRAY_SIZE_15]={0, 1, -3, 10, -1, 0, 0, 0, 0, 12, 1024, 10, 45, 6, 4};


int* bulles(int* tab, int size){
	for (int i=size-1;  i>=1; i--){
		for (int j=0; j<=i-1; j++){

			int x =tab[j+1];
			int y =tab[j];
			if (x<y){
				tab[j+1]= y;
				tab[j]=x ;
			}
		}
	}
	return tab;
}





void setup_TD3(void){
	bulles(arrayTest2, ARRAY_SIZE_15);
	displayArray_TD3(arrayTest2);

}



void loop_TD3(void){
	int sorted[ARRAY_SIZE_15]={0};
	long start=HAL_GetTick();
	sortArray(arrayTest2, sorted, ARRAY_SIZE_15);
	long stop=HAL_GetTick();
	printf("Solved in %d milliseconds\n\r", stop-start);


	long start2=HAL_GetTick();
	bulles(arrayTest2, ARRAY_SIZE_15);
	long stop2=HAL_GetTick();
	printf("Solved in %d milliseconds\n\r", stop2-start2);

}

