/*
 * analyseParametres.c
 *
 *  Created on: 10 juin 2022
 *      Author: obfe6300
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

#include "../inc/fonctions.h"
#include "../inc/variables.h"
#include "../inc/tools.h"

void analyseParametres(int argc, char **argv){

    char parametre[MAX_SIZE * 2];
    int idxOperation = 0;
    int tailleNombre = 0;

    if (argc < 4){
        printf("ERREUR : manques des parametres\n");
        aide();
        exit(-1);
    }
    strcpy(nombre1,"");
    strcpy(nombre2,"");
    strcpy(resultat,"");
    operation = ' ';

    for (int i = 1 ; i < argc ; i++){
        strcpy(parametre, argv[i]);
        printf("Analyse du parametre %s\n", parametre);
        if (parametre[0] == '-' && parametre[1] == '-'){
            // c'est une option
        } else {
            // c'est un des parametres de l'operation
            switch (idxOperation){
                case 0 : // c'est le premier nombre
                    tailleNombre = strlen(parametre);
                    if (tailleNombre > plusGrandNombre) plusGrandNombre = tailleNombre;
	                strcpy(nombre1, parametre);
                    break;
                case 1 : // c'est le symbole de l'opération
	                operation=parametre[0];
                    break;
                case 2 : // c'est le deuxieme nombre
                    tailleNombre = strlen(parametre);
                    if (tailleNombre > plusGrandNombre) plusGrandNombre = tailleNombre;
	                strcpy(nombre2, parametre);
                    break;
                default : // c'est un parametre non attendu
                    printf("Ce parametre (%s) n'est pas conforme a la syntaxe attendue\n", parametre);
                    aide();
                    exit(-1);
                    break;
            }
            idxOperation++;
        }
    }
    if (checkNumber(nombre1) != TRUE){
        printf("ERREUR : le premier nombre (%s) est invalide\n",nombre1);
        aide();
        exit(-1);
    }
    if (operation != '+' && operation != '-' && operation != 'x' && operation != ':'){
        printf("ERREUR : le parametre (%c) n'est pas un symbole d'operation \n",operation);
        aide();
        exit(-1);
    }
    if (checkNumber(nombre2) != TRUE){
        printf("ERREUR : le deuxieme nombre (%s) est invalide\n",nombre2);
        aide();
        exit(-1);
    }

}