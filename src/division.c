/*
 * division.c
 *
 *  Created on: 13 févr. 2018
 *      Author: obfe6300
 */

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../inc/variables.h"
#include "../inc/fonctions.h"
#include "../inc/tools.h"


char *division(char *nombre1, char*nombre2, char *resultat){
	char tmp1[MAX_SIZE];
	char reste[MAX_SIZE];
	char zeros[MAX_SIZE];
	char increment[MAX_SIZE];
	char soustracteur[MAX_SIZE];
	int diff_digits;
	//int retenue = 0;

	sprintf(resultat, "ERREUR : (compare)impossible de diviser %s par %s (pas de division reelle)",nombre1,nombre2);

	if (compare(nombre1, nombre2) < 0){
		return resultat;
	}

	//printf("-----\n");
	strcpy(reste,nombre1);
	strcpy(resultat,"0");
	while (compare(reste,nombre2) >= 0){
		diff_digits = strlen(reste) - strlen(nombre2) - 1;
		// on ajoute diff_digits 0 a nombre2 pour soustraire ce nombre
		// on ajoute du meme coup ce nobre de 0 a l'increment du quotient
		strcpy(zeros,"");
		int i=0;
		while (i < diff_digits){
		//for (int i=0 ; i >= diff_digits ; i++){
			i++;
			strcat(zeros,"0");
		}
		strcpy(tmp1, reste);
		strcpy(soustracteur,nombre2);
		strcat(soustracteur,zeros);
		//printf("soustraction de %s de %s \n", soustracteur, reste);
		soustraction(tmp1, soustracteur, reste);
		strcpy(tmp1, resultat);
		strcpy(increment,"1");
		strcat(increment,zeros);
		addition(tmp1, increment, resultat);
		//printf("resultat = %\n", resultat);
	}

	//printf("division : resultat = <%s>\n", resultat);
	return resultat;
}