



#ifndef INC_TD4_H_
#define INC_TD4_H_
#define ARRAY_SIZE_6 6
#define size_max 16

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ALPHABET_SIZE 36


void tri_insertion( int* tab, int size);
void displayArray_TD4(char* array);


char lookupInBaseFromCode(char* code);
char* lookupInBaseFromLetter(char letter);
char waitForInput(char previousInput);
void loop_TD4(void);
char* extract_mot(char tab[size_max]) ;
char* coupe(char* phrase, int i);
char* decode(char phrase[size_max][size_max]);

#endif /* INC_TD4_H_ */
