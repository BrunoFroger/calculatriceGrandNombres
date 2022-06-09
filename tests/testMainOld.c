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

#include "../inc/constantes.h"
#include "testTools.h"


int main(int argc, char **argv){
	char nombre1[MAX_SIZE];
	char nombre2[MAX_SIZE];
	char resultat[MAX_SIZE];
	char operation;
	char programme[250];

	strcpy(programme,"bin/calculatriceGrandsNombres");

	system("rm bin/resultat.txt");
	system("touch bin/resultat.txt");
	printf("================\n");
	printf("debut des tests \n");
	printf("----------------\n");
	printf(" tests mauvaises valeurs\n");
	testEquals(programme, "12 = 34", "calculatriceGrandsNombres nombre1 operation nombre2");
	testEquals(programme, "1a2 + 34", "calculatriceGrandsNombres nombre1 operation nombre2");
	testEquals(programme, "12 + 3b4", "calculatriceGrandsNombres nombre1 operation nombre2");
	printf("----------------\n");
	printf(" tests additions\n");
	testEquals(programme, "12 + 34", "12 + 34 = 46");
	testEquals(programme, "17 + 34", "17 + 34 = 51");
	testEquals(programme, "80 + 34", "80 + 34 = 114");
	testEquals(programme, "100 + 25", "100 + 25 = 125");
	testEquals(programme, "10000 + 25", "10000 + 25 = 10025");
	testEquals(programme, "25 + 10000", "25 + 10000 = 10025");
	testEquals(programme, "1234567890123456789012345678901234567890 + 1234567890123456789012345678901234567890", "1234567890123456789012345678901234567890 + 1234567890123456789012345678901234567890 = 2469135780246913578024691357802469135780");
	printf("----------------\n");
	printf(" tests soustractions\n");
	testEquals(programme, "43 - 12", "43 - 12 = 31");
	testEquals(programme, "100 - 50", "100 - 50 = 50");
	printf("----------------\n");
	printf(" tests multiplications\n");
	testEquals(programme, "3 x 4", "3 x 4 = 12");
	testEquals(programme, "8 x 4", "8 x 4 = 32");
	testEquals(programme, "456 x 3", "456 x 3 = 1368");
	testEquals(programme, "2 x 12", "2 x 12 = 24");
	testEquals(programme, "456 x 123", "456 x 123 = 56088");	
	testEquals(programme, "12345678901234567890 x 100000000", "12345678901234567890 x 100000000 = 1234567890123456789000000000");	
	printf("----------------\n");
	printf(" tests divisions\n");
	testEquals(programme, "8 : 40", "8 : 40 = ERREUR : (compare)impossible de diviser 8 par 40 (pas de division reelle)");
	testEquals(programme, "25 : 40", "25 : 40 = ERREUR : (compare)impossible de diviser 25 par 40 (pas de division reelle)");
	testEquals(programme, "8 : 4", "8 : 4 = 2");
	testEquals(programme, "100 : 20", "100 : 20 = 5");
	testEquals(programme, "100 : 5", "100 : 5 = 20");
	testEquals(programme, "80 : 40", "80 : 40 = 2");
	testEquals(programme, "100 : 5", "100 : 5 = 20");
	testEquals(programme, "100000 : 5", "100000 : 5 = 20000");
	testEquals(programme, "12345678901234567890 : 123", "12345678901234567890 : 123 = 100371373180768844");
	return 0;
}
