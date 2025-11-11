
#ifndef INC_SENSOR_H_
#define INC_SENSOR_H_


#define SENSOR_NUMBER 5

typedef enum {
	INACTIVE,
	ACTIVE ,

}SENSOR_STATE;


typedef struct sensor {
	int id ;
	float threshold;
	float value;
	SENSOR_STATE state;

} SENSOR;

typedef struct sensor_array{
	SENSOR tab[SENSOR_NUMBER] ;

} SENSOR_ARRAY;


void init_system(SENSOR_ARRAY * system);
void setup_sensor();
void display_system(SENSOR_ARRAY  system[2]);
void read_sensors(SENSOR_ARRAY * system);
void check_threshold(SENSOR * sensor);
void display_sensor( SENSOR* sensor);
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);

#endif /* INC_SENSOR_H_ */
