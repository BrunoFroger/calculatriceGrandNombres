/*
 * soustraction.c
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


char *soustraction(char *nombre1, char*nombre2, char *resultat){
	int max_len;
	char tmp1[MAX_SIZE];
	char tmp2[MAX_SIZE];
	int digit1, digit2, diff;
	int retenue = 0;
	//int negatif = 0;

	strcpy(tmp1,nombre1);
	reverse(tmp1);
	strcpy(tmp2,nombre2);
	reverse(tmp2);

	//printf("soustraction sur les reverses %s et %s\n", tmp1, tmp2);

	max_len = strlen(nombre1);
	if (compare(nombre1, nombre2) < 0){
		max_len = strlen(nombre2);
		sprintf(resultat,"ERREUR : impossible de soustraire %s de %s (pas de soustraction negative permise)", nombre2, nombre1);
		printf("%s\n",resultat);
	} else {
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
			diff = digit1 - digit2 - retenue;
			//printf("soustraction (%d) %d - %d = %d\n", i, digit1, digit2, diff);
			if (diff < 0){
				resultat[i] = diff + 10 ;
				retenue = 1;
			}else{
				resultat[i] = diff;
				retenue = 0;
			}
			resultat[i] += '0';
			resultat[i+1]='\0';
			//printf("soustraction : resultat = <%s>\n", resultat);
		}
		reverse(resultat);
		suppZeroDebut(resultat);
	}

	if (strlen(resultat) == 0) strcpy(resultat, "0");
	//printf("=================> soustraction : %s - %s = <%s>\n", nombre1, nombre2, resultat);
	return resultat;
}