//Mikolaj Koszowski
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h> 
#include "obiekty.h"

int main (int argc, char *arg[])
{
	srand(time(NULL));
	if(argc!=5){
		puts("Blad");
		exit (1);
	}
	
	//char par[2];
	//strcpy(par,arg[1]);
	int n=atof(arg[2]);
	double a=atof(arg[3]);
	double b=atof(arg[4]);
	double s=0,m=0;
	
	
	double(*gen) (double,double);
	if(!strcmp(arg[1],"-G")) gen=genG;
	else if(!strcmp(arg[1],"-J"))gen=genJ;
	
	double* tab=generator(gen,n,a,b);
	wypisz(stderr,tab,n);
	stat(tab,n,m,s);
	
	
	
		
		
		
	return 0;
		
	}
