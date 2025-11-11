#include <stdio.h>
#include <stm32l4xx_hal.h>
#include "tab_td2.h"
#define ARRAY_SIZE 3




void setup4(void){
setvbuf(stdin, NULL, _IONBF, 0);
// Ce setup est indispensable pour scanf.
}





void displayArray_fake(int array[ARRAY_SIZE]){
int i;
for (i = 0; i < ARRAY_SIZE; i++){
printf("array[%d] = %d\n\r", i, array[i]);
}
}







void loop4(void){
	int array[ARRAY_SIZE] = {0};
	int index;
	while (1){
		scanf("%d", &index);
		array[index] = 1;
		displayArray_fake(array);
	}
}
