#ifndef _obiekty_h_
#define _obiekty_h_

#include "obiekty.cpp"
#include <math.h> 
#include <stdio.h>
#include <stdlib.h>


struct kapeluszW{
	float m;
	float h;
	float r;	
};

struct kapeluszP{
	float m;
	float h;
	float a;
	float b;
};

struct kapeluszT{
	float m;
	float h;
	float a;
};

union kapelusz{
	struct kapeluszW wa;
	struct kapeluszP pr;
	struct kapeluszT tr;
};

enum kszt{KOLO,KWADRAT,TROJKAT};

struct Kapelusz{
	union kapelusz kape;
	kszt k;
};

struct StatParam{
	
	float avh;
	float uavh;
	float masa;
	float obj;
		
};

Kapelusz *wczytaj_dane(FILE *we, size_t &rozmiar);

StatParam oblicz(const Kapelusz *tk, size_t n);





#endif
