/*
 * multiplication.c
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
#include "../inc/fonctions.h"


//-----------------------------------------------------------
//
//			multiplication
//
//-----------------------------------------------------------
char *multiplication(char *nombre1, char*nombre2, char *resultat){
	//int max_len;
	char tmp1[MAX_SIZE];
	char tmp2[MAX_SIZE];
	char tmp3[MAX_SIZE];
	char somme[MAX_SIZE];
	int digit1, digit2, produit;
	int retenue = 0;
	//int negatif = 0;

	strcpy(resultat,"0");
	strcpy(somme,"0");
	
	if (strlen(nombre1) >= strlen(nombre2)){
		strcpy(tmp1,nombre1);
		strcpy(tmp2,nombre2);
	}else{
		strcpy(tmp1,nombre2);
		strcpy(tmp2,nombre1);
	}
	if (verbose) printf("-----\n");
	if (verbose) printf("multiplication des nombres : %s x %s \n", tmp1, tmp2);

	if (strlen(tmp2) != 1){
		// on decale le nombre 2 a droite
		//printf("plus de 2 digit dans nombre 2, on decompose %s, %s \n", tmp1, tmp2);
		strcpy(tmp3,tmp2);
		tmp3[strlen(tmp3)-1]='\0';
		strcpy(resultat,"");
		multiplication(tmp1, tmp3, resultat);
		addition(somme,resultat, somme);
		tmp3[0]=tmp2[strlen(tmp2)-1];
		tmp3[1]='\0';
		multiplication(tmp1, tmp3, resultat);
		// decalage a droite du resultat de cette multiplication ( X 10)
		somme[strlen(somme)+1] = '\0';
		somme[strlen(somme)] = '0';
		strcpy(tmp3, somme);
		addition(tmp3, resultat, somme);
		//printf("addition sortie => %s + %s = <%s>\n", tmp3, resultat, somme);
		strcpy(resultat, somme);
	}else{
		// multiplication sur 1 digit, on calcule
		//printf("1 seul digit dans nombre 2, on calcule <%s> x <%s> \n", tmp1, tmp2);
		digit2 = tmp2[0] - '0';
		strcpy(resultat,"");
		retenue = 0;
		resultat[strlen(tmp1)]='\0';
		for (int i = strlen(tmp1) -1 ; i >= 0 ; i--){
			// calcul du produit d'un digit avec nombre 1
			digit1 = tmp1[i] - '0';
			produit = digit1 * digit2 + retenue;
			//printf("resultat de multiplication des digits : %d x %d + %d = %d\n", digit1, digit2, retenue, produit);
			if (produit > 10){
				div_t divresult;
				divresult = div (produit,10);
				retenue = divresult.quot;
				resultat[i] = divresult.rem + '0';
				//printf("resultat[%d] = %c\n", i, resultat[i]);
			}else{
				resultat[i] = produit + '0';
				retenue = 0;
			}
			//resultat[i+1]='\0';
		}
		resultat[strlen(resultat)]='\0';
		if (retenue != 0){
			tmp3[0] = retenue + '0';
			tmp3[1] = '\0';
			strcat(tmp3,resultat);
			strcpy(resultat, tmp3);
		}
		if (verbose) printf("resultat de multiplication du nombres et digit %s x %s = %s\n", tmp1, tmp2, resultat);
	}

	//printf("multiplication sortie => %s x %s = <%s>\n", nombre1, nombre2, resultat);
	return resultat;
}