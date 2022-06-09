/*
 * tools.h
 *
 *  Created on: 13 févr. 2018
 *      Author: obfe6300
 */

#ifndef TESTS_TOOLS_H_
#define TESTS_TOOLS_H_

	extern int testResultat(char *expected);
	extern char *getResultat(char *resultat);
	extern int testEquals(char *nomProgramme, char *parametres, char *resultatAttendu);
	extern void reverse(char *str);

	#define MAX_NB_TESTS	100
	extern void addTest(char *commande, char *expectedResult);
	extern void execTests(char *programme);
	extern void initTests(void);
	extern void bilanTests(void);

#endif /* TESTS_TOOLS_H_ */
