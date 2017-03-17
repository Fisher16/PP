#ifndef _sygnal_h_
#define _sygnal_h_
#include <stdlib.h>
#include <stdio.h>
#include "arg.h"
#include "io.h"


double mx (const double *dane, size_t rozmiar);
double mn (const double *dane, size_t rozmiar);
sygnal wygladz (const sygnal &dane);
sygnal pochodna (const sygnal &dane);
sygnal calka (const sygnal &dane);
sygnal normalizuj (const sygnal &dane);

#endif
