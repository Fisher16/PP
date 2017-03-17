#ifndef _obiekty_h_
#define _obiekty_h_

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h> 


double genG(double m,double s);
double genJ(double min,double max);
double *generator(double (*gen) (double, double), int n, double a, double b);
void stat(const double dane[],int n, double &m, double &s);
void wypisz(FILE *wy,const double dane[], int n);

#endif
