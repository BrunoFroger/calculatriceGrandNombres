/*
 * addition.c
 *
 *  Created on: 13 févr. 2018
 *      Author: obfe6300
 */

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../inc/variables.h"
#include "../inc/tools.h"


char *addition(char *nombre1, char*nombre2, char *resultat){
	int max_len;
	char tmp1[MAX_SIZE];
	char tmp2[MAX_SIZE];
	int digit1, digit2, somme;
	int retenue = 0;

	strcpy(tmp1,nombre1);
	reverse(tmp1);
	strcpy(tmp2,nombre2);
	reverse(tmp2);

	//printf("addition sur les reverses %s et %s\n", tmp1, tmp2);

	max_len = strlen(nombre1);
	if (strlen(nombre2) > max_len){
		max_len = strlen(nombre2);
	}

	for (int i = 0 ; i < max_len ; i++){
		if (i >= strlen(tmp1)){
			digit1 = 0;
		}else{
			digit1 = tmp1[i] - '0';
		}
		if (i >= strlen(tmp2)){
			digit2 = 0;
		}else{
			digit2 = tmp2[i] - '0';
		}
		somme = digit1 + digit2 + retenue;
		//printf("addition (%d) %d + %d = %d\n", i, digit1, digit2, somme);
		if (somme > 9){
			resultat[i] = somme - 10 ;
			retenue = 1;
		}else{
			resultat[i] = somme;
			retenue = 0;
		}
		resultat[i] += '0';
		resultat[i+1]='\0';
		//printf("addition : resultat = <%s>\n", resultat);
	}
	reverse(resultat);
	if (retenue != 0){
		tmp1[0] = retenue + '0';
		tmp1[1] = '\0';
		strcat(tmp1,resultat);
		strcpy(resultat, tmp1);
	}
	//printf("addition : resultat = <%s>\n", resultat);
	return resultat;
}