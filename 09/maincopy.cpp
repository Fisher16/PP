//Mikolaj Koszowski
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h> 

double genG(double m,double s){
	double x=(double)rand()/RAND_MAX;
	double y= (double)rand()/RAND_MAX;
	double z1= sqrt (-2 * log (x)) * cos (2 * 3.1415926535 * y);
	//double z2= sqrt (-2 * log (x)) * sin (2 * 3.1415926535 * y);
	return s*z1+m;
}

double genJ(double min,double max){

	return (max-min)*((double)rand()/RAND_MAX)+min;
}

double *generator(double (*gen) (double, double), int n, double a, double b){
	double* tab=(double*)malloc(sizeof(double)*n);
	for(int i=0;i<n;i++){
		*tab=gen(a,b);
		tab++;
		
	}
	
	
	return tab-n;

}

void stat(const double dane[],int n, double &m, double &s){
	for(int i=0;i<n;i++)s+=dane[i];
	s/=n;
	for(int i=0;i<n;i++)m+=(dane[i]-s)*(dane[i]-s);
	m=sqrt(m/n);
	printf("%lf %lf\n",s,m);
	
}

void wypisz(FILE *wy,const double dane[], int n){
	
	for(int i=0;i<n;i++)fprintf(wy,"%lf\n",dane[i]);
}


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
	wypisz(stdout,tab,n);
	stat(tab,n,m,s);
	
	
	
		
		
		
	return 0;
		
	}
