//Mikolaj Koszowski
#include <math.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


double *wczytaj_dane (FILE *strumien, int *n)
{
		
		//strumien=fopen("dane.txt", "r");
		int b=0;
		b=fscanf(strumien,"%d",&b);
		double *tab=(double*)malloc(*n*sizeof(double));
		for(int i=0;i<*n;i++)fscanf(strumien,"%lf",&tab[i]);
		return tab;
}

void analiza_statystyczna (const double dane[], int n, double *m, double *s)
{
	double sr=0;
	double si=0;
	for(int i=0;i<n;i++)sr+=dane[i];
	sr/=n;
	for(int j=0;j<n;j++)si+=(dane[j]-sr)*(dane[j]-sr);
	si/=(n-1);
	si=sqrt(si);
	*s=sr;
	*m=si;
	
}

bool test_sigma (double liczba, double m, double s, double x)
{
	if(liczba>=(s-x*m)&&liczba<=(s+x*m))return true;
	else return false;

}
int main(void)
{
	int n;
	//FILE *strumien;
	scanf("%d",&n);
	double *tab=wczytaj_dane(strumien,&n);
	//for(int i=0;i<n;i++)printf("%lf\n",tab[i]);
	//printf("%d\n",n);
	
	double s,m;
	analiza_statystyczna(tab,n,&m,&s);
	printf("Srednia %lf sigma %lf\n",s,m);
	double ile=0;
	for(int i=0;i<n;i++)if(!test_sigma(tab[i],m,s,3))ile++;
	printf("Nie spelnia %.0lf czyli %lf procent\n",ile,ile/n);
	
	free(tab);
	return 0;
}
