/*
 * tools.c
 *
 *  Created on: 13 févr. 2018
 *      Author: obfe6300
 */

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../inc/variables.h"

void reverse(char *str){
    char temp[MAX_SIZE];
    int k=0;

    //int pos = strlen(str)-1;
    for(int i = strlen(str)-1; i >= 0; i--)
    {
       	temp[k++]=str[i];
    }
    temp[k]='\0';
    strcpy(str,temp);
}

void suppZeroDebut(char *str){
    char temp[MAX_SIZE];
    int k=0;
    for (int i = 0 ; i < strlen(str) ; i++){
    	if (!(k == 0 && str[i] == '0')){
    		temp[k++] = str[i];
    	}
    }
    temp[k]='\0';
    strcpy(str,temp);
}

int compare(char *str1, char *str2){
	// comparation de nombre en chaines de caracteres
	// resultats :
	// 0 si str1 = str2
	// -1 si str1 < str2
	// 1 si str1 > str2
	if (strcmp(str1,str2) == 0){
		//printf("compare : str1 = str2\n");
		return 0;
	}
	if (strlen(str1) < strlen(str2)){
		//printf("compare len : str1 < str2\n");
		return -1;
	}
	if (strlen(str1) > strlen(str2)){
		//printf("compare len : str1 > str2\n");
		return 1;
	}
	// on traite le cas ou les longeurs sont identiques
	// on compare alors le premier digit
	if (str1[0] < str2[0]){
		//printf("compare first digit : str1 < str2\n");
		return -1;
	}
	if (str1[0] > str2[0]){
		//printf("compare first digit : str1 > str2\n");
		return 1;
	}
	//printf("compare first digit : str1 = str2\n");
	return 0;
}


int checkNumber(char *number){
	for (int i = 0 ; i < strlen(number) ; i++){
		if (number[i] < '0' || number[i] > '9'){
			return FALSE;
		}
	}
	return TRUE;
}
