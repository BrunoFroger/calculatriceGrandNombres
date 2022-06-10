/*
 * testsMain.c
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
#include "testTools.h"

typedef struct {
		char commande[MAX_SIZE];
		char expectedResult[MAX_SIZE];
	} testCase;

testCase testsCases[MAX_NB_TESTS];
int indexTest,cptOK=0,cptKO=0,cptTests=0,testKO=-1;
int plusGrandNombreTest;
char tailleNombre[20];

char *getResultat(char *resultat){
	FILE *fic;
	char ligne[MAX_SIZE];
	int cptLigne=0;
	int verbose = 0;

	if (verbose) printf("Debut lecture du fichier resultat\n");	
	fic = fopen("bin/resultat.txt", "r");
	while (! feof(fic)){
		if (fgets(ligne, MAX_SIZE, fic) != NULL){
			ligne[strlen(ligne)-1]='\0';
			if (verbose) printf("	Lecture fichier resultat (%d) => ligne <%s> : ", cptLigne, ligne);
			strcpy(resultat, ligne);
		}
		if (verbose) printf("\n");
		cptLigne++;
	}
	if (atoi(tailleNombre) > plusGrandNombreTest) plusGrandNombreTest = atoi(tailleNombre);
	
	if (verbose) printf("fin lecture du fichier resultat => %s\n", resultat);
	return resultat;
}

int testResultat(char *expected){
	//FILE *fic;
	char resultat[MAX_SIZE];

	if (strcmp(expected, getResultat(resultat)) != 0){
		return FALSE;
	}
	return TRUE;
}

int testEquals(char *nomProgramme, char *parametres, char *resultatAttendu){
	char commande[MAX_SIZE];
	char commandeSystem[MAX_SIZE];
	char tmp[MAX_SIZE];
	int valRetour;
	char message[MAX_SIZE * 3 + 100];

	time_t timeDebut, timeFin;
	//time(&timeDebut);
	timeDebut = clock();
	sprintf(commande, "%s %s",nomProgramme, parametres);
	sprintf(message, "test %3d : <%s> ; resultat attendu = <%s> ",cptTests, parametres, resultatAttendu);
	sprintf(commandeSystem, "%s > bin/resultat.txt",commande);
	system(commandeSystem);
	strcpy(tmp,getResultat(tmp));
	valRetour = testResultat(resultatAttendu);
	if (valRetour == FALSE){
		sprintf(message, "%s ==> KO (%s) ", message, tmp);
	} else {
		sprintf(message, "%s ==> OK ", message);
		if (strlen(tmp)> plusGrandNombreTest) plusGrandNombreTest = strlen(tmp);
	}
	//time(&timeFin);
	timeFin = clock();
	//printf(" (duree du test : %5f ms)\n", (float)(timeFin - timeDebut) * 1000.0 / CLOCKS_PER_SEC);
	sprintf(message, "%s (duree du test : %ld micro seconds)", message, (timeFin - timeDebut));
	if ((valRetour == FALSE) || (verbose == 1)) printf("%s\n", message);
	return valRetour;
}

void addTest(char *commande, char *expectedResult){
	testCase *tmp;
	tmp = &testsCases[indexTest];
	strcpy(tmp->commande,commande);
	strcpy(tmp->expectedResult,expectedResult);
	indexTest++;
}

void initTests(void){
	testCase *tmp;
	for (int i = 0 ; i < MAX_NB_TESTS ; i++){
		tmp = &testsCases[i];
		strcpy(tmp->commande,"");
		strcpy(tmp->expectedResult,"");
	}
	indexTest=0;
}

void execTests(char *programme){
	testCase *tmp;
	int i = 0;
	int nbOK = 0;
	int nbKO = 0;
	int result;
	for (i = 0 ; i < MAX_NB_TESTS ; i++){
		tmp = &testsCases[i];
		if (strcmp(tmp->commande,"") == 0){
			break;
		}
		result = testEquals(programme, tmp->commande, tmp->expectedResult);
		if (result == TRUE){
			cptOK++;
			nbOK++;
		}else{
			cptKO++;
			nbKO++;
			testKO=cptTests;
		}
		cptTests++;
	}
	printf(" %d tests executés : %d OK, %d KO\n", i, nbOK, nbKO);
}

void bilanTests(void){
	printf("Bilan des tests :\n");
	printf("Nombre tests executés    : %3d\n",cptTests);
	printf("       tests OK          : %3d (%d%%)\n",cptOK,cptOK*100/cptTests);
	printf("       tests KO          : %3d (%d%%)\n",cptKO,cptKO*100/cptTests);
	printf("Plus grand nombre        : %3d chiffres\n",plusGrandNombreTest);
	if (testKO != -1){
		printf("  id dernier test KO  : %3d \n",testKO);
	}
}
