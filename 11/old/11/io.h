#ifndef _io_h_
#define _io_h_
#include <stdlib.h>
#include <stdio.h>
struct sygnal{
	double* x;
	double* y;
	int rozm;
};
sygnal wczytaj_dane (const opcje_programu &op);
void zapisz_dane (const opcje_programu &op,const sygnal &dane);
void binprint(void);
#endif
