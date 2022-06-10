/*
 * main.c
 *
 *  Created on: 13 févr. 2018
 *      Author: obfe6300
 */

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../inc/variables.h"
#include "../inc/fonctions.h"
#include "../inc/tools.h"

int main(int argc, char **argv){
	char nombre1[MAX_SIZE];
	char nombre2[MAX_SIZE];
	char resultat[MAX_SIZE];
	char operation;
	time_t timeDebut, timeFin;

	if (argc != 4){
		printf("ERREUR : pas le bon nombre d'arguments (%d) ! \n", argc);
		for (int i = 0 ; i < argc ; i++){
			printf("%s ",argv[i]);
		}
		printf("\n");
		aide();
		return -1;
	}
	int taille = strlen(argv[1]);
	if (taille > plusGrandNombre) plusGrandNombre = taille;
	if (taille > MAX_SIZE){
		printf("ERREUR : le premier parametre est trop grand taille > à %d\n",MAX_SIZE);
		aide();
		return -1;
	}
	taille = strlen(argv[2]);
	if (taille > plusGrandNombre) plusGrandNombre = taille;
	if (taille > MAX_SIZE){
		printf("ERREUR : le deuxieme parametre est trop grand taille > à %d\n",MAX_SIZE);
		aide();
		return -1;
	}
	strcpy(nombre1, argv[1]);
	strcpy(nombre2, argv[2]);
	operation=nombre2[0];
	strcpy(nombre2, argv[3]);
	strcpy(resultat,"");

	if (checkNumber(nombre1) != TRUE){
		printf("ERREUR : le premier parametre n'est pas un nombre (%s)\n",nombre1);
		aide();
		return -1;
	}
	if (checkNumber(nombre2) != TRUE){
		printf("ERREUR : le troisieme parametre n'est pas un nombre (%s)\n",nombre2);
		aide();
		return -1;
	}
	if (operation != '+' && operation != '-' && operation != 'x' && operation != ':'){
		printf("ERREUR : le deuxieme parametre n'est pas un symbole d'operation (%c)\n",operation);
		aide();
		return -1;
	}

	//printf("Main : Execution de l'operation %s %c %s \n", nombre1, operation, nombre2);
	timeDebut = clock();
	switch (operation){
		case '+':
			printf("%s + %s = ", nombre1, nombre2);
			addition(nombre1, nombre2, resultat);
			printf("%s\n", resultat);
			break;
		case '-':
			printf("%s - %s = ", nombre1, nombre2);
			soustraction(nombre1, nombre2, resultat);
			printf("%s\n", resultat);
			break;
		case 'x':
		case 'X':
			printf("%s x %s = ", nombre1, nombre2);
			multiplication(nombre1, nombre2, resultat);
			printf("%s\n", resultat);
			break;
		case ':':
			printf("%s : %s = ", nombre1, nombre2);
			division(nombre1, nombre2, resultat);
			printf("%s\n", resultat);
			break;
		default :
			printf("ERREUR : operateur inconnu %c\n", operation);
			aide();
			break;
	}
	//printf("resultat = %s ; taille : %lu\n", resultat, strlen(resultat));
	printf("%s\n", resultat);
	//printf("%d\n", plusGrandNombre);
	if (strlen(resultat) > plusGrandNombre) plusGrandNombre = strlen(resultat);
	timeFin = clock();
	//printf("duree du test : %f\n", (float)(timeFin - timeDebut) * 1000 /CLOCKS_PER_SEC);
	return 0;
}

