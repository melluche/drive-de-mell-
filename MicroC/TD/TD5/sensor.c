#include <stdio.h>
#include <string.h>
#include <stm32l4xx_hal.h>
#include <stdlib.h>
#include "sensor.h"
#define SENSOR_NUMBER 5


void init_system(SENSOR_ARRAY * system){
	for (int i=0; i<2; i++){
		for (int j=0; j<SENSOR_NUMBER; j++){
			float c =  ((float) rand() / RAND_MAX) * 10;
			system[i].tab[j].threshold=c;
			system[i].tab[j].state=INACTIVE;
		}
	}

}






SENSOR_ARRAY system1[2] = {
    {   // premier SENSOR_ARRAY
        {   // son champ .tab
            {1, 0.4, 0.5, ACTIVE},
            {2, 3.1, 1.5, ACTIVE},
            {3, 4.1, 2.5, ACTIVE},
            {4, 4.1, 3.5, ACTIVE},
            {5, 4.1, 4.5, ACTIVE}
        }
    },
    {   // deuxième SENSOR_ARRAY
        {
            {6, 0.4, 0.5, ACTIVE},
            {7, 3.1, 1.5, ACTIVE},
            {8, 4.1, 2.5, ACTIVE},
            {9, 4.1, 3.5, ACTIVE},
            {10, 4.1, 4.5, ACTIVE}
        }
    }
};


void display_system(SENSOR_ARRAY system[2]) {
    for (int i = 0; i < 2; i++) {
        printf("=== System %d ===\r\n", i);
        for (int j = 0; j < SENSOR_NUMBER; j++) {
            printf(" id : %d\n", system[i].tab[j].id);
            printf("  threshold = %.2f\r\n", system[i].tab[j].threshold);
            printf("  value     = %.2f\r\n", system[i].tab[j].value);
            printf("  state     = %s\r\n",
                   system[i].tab[j].state == ACTIVE ? "ACTIVE" : "INACTIVE");
        }
    }
}



void read_sensors(SENSOR_ARRAY * system){
	for (int i=0; i<1; i++){
		for (int j=0; j< SENSOR_NUMBER; j++){
			float valeur =((float) rand() / RAND_MAX) * 10;
			system[i].tab[j].value= valeur;

		}
	}

}

void check_threshold(SENSOR * sensor){

		if (sensor->value > sensor->threshold ){
			sensor->state= ACTIVE;
		}
		else{
			sensor->state= INACTIVE;

	}

}



void display_sensor( SENSOR* sensor){
	for( int i=0; i <2; i++){
		printf(" id : %d \r\n", sensor->id);
		printf("  threshold = %.2f\r\n",sensor->threshold);
		printf("  value     = %.2f\r\n", sensor->value);
		printf("  state     = %s \r\n", sensor->state == ACTIVE ? "ACTIVE" : "INACTIVE");
		  }
	}






void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
	if(GPIO_Pin == GPIO_PIN_13) {
		printf("tu appuies chéri \r\n ");

	}
}
void loop_sensor(){

}

void setup_sensor(){

}



/* LIAISON ET BUS  */



































