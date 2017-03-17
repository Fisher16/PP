#ifndef _arg_h_
#define _arg_h_
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
enum rodzaj_pliku{BINARNY,TEKSTOWY};
enum rodzaj_opt{SOPT, DOPT, IOPT, POPT};


struct opcje_programu{
	char we[65];
	rodzaj_pliku rdzp;
	rodzaj_opt rdzo;
	char wy[65];
	bool graf;

};

opcje_programu analizuj_opcje_programu (int argc, char *arg[]);



#endif
