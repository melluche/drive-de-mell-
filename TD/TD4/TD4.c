
#define ARRAY_SIZE_6 6
#include <stdio.h>
#include <string.h>
#include <stm32l4xx_hal.h>
#include <stdlib.h>
#include "TD4.h"
#define ALPHABET_SIZE 36
#define size_max 16
int tab_test[ARRAY_SIZE_6]={1,-2,4,-3,10,0};

void tri_insertion(int* tab, int n){
	for ( int i=1;i<n;i++){
		int x;
		x=tab[i];
		int j;
		j=i;
		while ( j>0 && tab[j-1]>x){
			tab[j]=tab[j-1];
			j=j-1;
		}
		tab[j]=x;
	}
}


typedef struct morse_lettre {
char letter;
char * code;
} MORSE_LETTRE;

const MORSE_LETTRE alphabet[ALPHABET_SIZE] =
{ {'A',".-"},{'B',"-..."},{'C',"-.-."},
{'D',"-.."},{'E',"."},{'F',"..-."},
{'G',"--."},{'H',"...."},{'I',".."},
{'J',".---"},{'K',"-.-"},{'L',".-.."},
{'M',"--"},{'N',"-."},{'O',"---"},
{'P',".--."},{'Q',"--.-"},{'R',".-."},
{'S',"..."},{'T',"-"},{'U',"..-"},
{'V',"...-"},{'W',".--"},{'X',"-..-"},
{'Y',"-.--"},{'Z',"--.."},
{'1',".----"},{'2',"..---"},{'3',"...--"},
{'4',"....-"},{'5',"....."},{'6',"-...."},
{'7',"--..."},{'8',"---.."},{'9',"----."},
{'0',"-----"}
};




void displayArray_TD4(char* array){
	int i;
	for (i = 0; i < size_max; i++){
		printf("array[%d] = %c\n\r", i, array[i]);
	}
}


char lookupInBaseFromCode(char* code){
	for (int el=0; el<=ALPHABET_SIZE; el++){
		if (   strcmp(alphabet[el].code, code)==0 ){

			return alphabet[el].letter;

		}

	}
	return '0';

}


char* lookupInBaseFromLetter(char letter){
	for (int i=0; i<=ALPHABET_SIZE; i++){
		if (letter== alphabet[i].letter){
			return alphabet[i].code;

		}

	}
	return '0';
}



char waitForInput(char previousInput){
	if (previousInput==' '){
		while (   (HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_13))==1 ){
		}
	}
	int temps1=HAL_GetTick();

	while (   (HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_13))==1 ){
			}
	int temps4=HAL_GetTick();

	if ( temps4-temps1 >=1000){
		return ' ';
	}



	while( (HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_13))==0){

	}
	int temps2=HAL_GetTick();

	int delta= temps2-temps4;
	if ( delta<200){
			return '.';
		}

	if ( delta>=200){
			return '-';
		}
	}




char* extract_mot(char tab[size_max]) {
    static char mot[size_max];
    int i = 0;


    mot[0] = '\0';

    // Parcours jusqu'au premier espace ou fin de chaîne
    while (tab[i] != ' ' && tab[i] != '\0') {
        int len = strlen(mot);
        mot[len] = tab[i];     // ajoute le caractère
        mot[len + 1] = '\0';   // termine la chaîne
        i++;
    }

    return mot;
}



char* coupe(char* phrase, int i) {
    static char phrase2[size_max]; // static pour pouvoir retourner un pointeur
    int c = 0;

    // Parcours à partir de l'index i
    for (int j = i; j < strlen(phrase); j++) {
        phrase2[c] = phrase[j];
        c++;
    }
    phrase2[c] = '\0'; // terminer la chaîne

    return phrase2;
}




char* decode(char phrase[size_max][size_max]) {
    static char mot[size_max];  // static pour pouvoir retourner un pointeur
    mot[0] = '\0';

    for (int i = 0; i < size_max; i++) {
        if (strlen(phrase[i]) == 0) break;  // fin des mots valides

        char lettre = lookupInBaseFromCode(phrase[i]);
        if (lettre != '0') {
            int len = strlen(mot);
            mot[len] = lettre;
            mot[len + 1] = '\0';
        }
    }

    return mot;
}

void loop_TD4(void) {
    char phrase[size_max][size_max];
    char prev = ' ';
    char recue[size_max];
    int i = 0;


    while (i < size_max) {
        prev = waitForInput(prev);
        recue[i] = prev;
        i++;
    }
    recue[i] = '\0';

    int index = 0;
    int cpt2 = 0;

    char* ptr_rec = recue;

    displayArray_TD4(recue);



    while (strlen(ptr_rec) > 0) {
        char* mot = extract_mot(ptr_rec);
        strcpy(phrase[index], mot);
        index++;

        int n2 = strlen(mot);
        cpt2 += n2;

        ptr_rec = coupe(ptr_rec, cpt2);
        if (ptr_rec[0] == ' ') {
        	ptr_rec = coupe(ptr_rec, 1);
        }
    }

    for (int j = 0; j < index; j++) {
         printf("mot[%d] = %s \r\n", j, phrase[j]);
     }

    printf(" voici le message: %s \r\n",decode(phrase) );

    printf("---------------------- \r\n");


}



