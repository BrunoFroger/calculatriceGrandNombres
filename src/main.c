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
#include "../inc/analyseParametres.h"

//-----------------------------------------------------------
//
//			main
//
//-----------------------------------------------------------
int main(int argc, char **argv){
	time_t timeDebut, timeFin;
	printf("Debut du programme %s \n", argv[0]);
	analyseParametres(argc, argv);

	printf("Main : Execution de l'operation %s %c %s \n", nombre1, operation, nombre2);
	timeDebut = clock();
	switch (operation){
		case '+':
			if (verbose) printf("%s + %s = ", nombre1, nombre2);
			addition(nombre1, nombre2, resultat);
			if (verbose) printf("%s\n", resultat);
			break;
		case '-':
			if (verbose) printf("%s - %s = ", nombre1, nombre2);
			soustraction(nombre1, nombre2, resultat);
			if (verbose) printf("%s\n", resultat);
			break;
		case 'x':
		case 'X':
			if (verbose) printf("%s x %s = ", nombre1, nombre2);
			multiplication(nombre1, nombre2, resultat);
			if (verbose) printf("%s\n", resultat);
			break;
		case ':':
			if (verbose) printf("%s : %s = ", nombre1, nombre2);
			division(nombre1, nombre2, resultat);
			if (verbose) printf("%s\n", resultat);
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

