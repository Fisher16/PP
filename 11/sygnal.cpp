#include "sygnal.h"
#include "io.h"
#include "arg.h"



double mx (const double *dane, size_t rozmiar){
    double maks=*dane;
    for(size_t i=0;i<rozmiar;i++)if(maks<*(dane+i))maks=*(dane+i);

    return maks;
}
double mn (const double *dane, size_t rozmiar){
    double mini=*dane;
    for(size_t i=0;i<rozmiar;i++)if(mini>*(dane+i))mini=*(dane+i);

    return mini;
}

sygnal wygladz (const sygnal &dane){
	sygnal tab={NULL,NULL,dane.rozm-2};
	tab.y=(double*)malloc(sizeof(double)*tab.rozm-2);
	tab.x=(double*)malloc(sizeof(double)*tab.rozm-2);
	for(int i=2;i<dane.rozm-1;i++){
		*(tab.y+i-2+1)=*(dane.y+i-2)+*(dane.y+1+i-2)+*(dane.y+i);
		*(tab.y+i-2+1)/=3;
	}
	for(int i=2;i<dane.rozm-1;i++){
		*(tab.x+i-2)=*(dane.x+i-2);
	}

	return tab;
}
sygnal pochodna (const sygnal &dane){
	sygnal tab={NULL,NULL,dane.rozm-2};
	tab.y=(double*)malloc(sizeof(double)*tab.rozm-2);
	tab.x=(double*)malloc(sizeof(double)*tab.rozm-2);
	for(int i=0;i<dane.rozm-1;i++){
		*(tab.y+i)=(*(dane.y+i+1)-*(dane.y+i))/(*(dane.x+i+1)-*(dane.x+i));
	}
	for(int i=0;i<dane.rozm-1;i++){
		*(tab.x+i)=*(dane.x+i);
	}

	return tab;
}

sygnal calka (const sygnal &dane){
	sygnal tab={NULL,NULL,dane.rozm-2};
	tab.y=(double*)malloc(sizeof(double)*tab.rozm-2);
	tab.x=(double*)malloc(sizeof(double)*tab.rozm-2);
	*(tab.y)=*(dane.y)*(*(dane.x+1)-*dane.x);
	for(int i=1;i<dane.rozm-1;i++){
		*(tab.y+i)=*(tab.y+i-1)+*(dane.y+i)*(*(dane.x+1+i)-*(dane.x+i));

	}
	for(int i=0;i<dane.rozm-1;i++){
		*(tab.x+i)=*(dane.x+i);

	}


	return tab;
}

sygnal normalizuj (const sygnal &dane){
	sygnal tab={NULL,NULL,dane.rozm};
	tab.y=(double*)malloc(sizeof(double)*tab.rozm);
	tab.x=(double*)malloc(sizeof(double)*tab.rozm);
	for(int i=0;i<dane.rozm;i++){
		tab.x[i]=2*(dane.x[i]-mn(dane.x,dane.rozm))/(mx(dane.x,dane.rozm)-mn(dane.x,dane.rozm))-1;

	}
	for(int i=0;i<dane.rozm;i++){
		tab.y[i]=2*(dane.y[i]-mn(dane.y,dane.rozm))/(mx(dane.y,dane.rozm)-mn(dane.y,dane.rozm))-1;
		printf("%d %lf\t%lf\n",i,tab.x[i],tab.y[i]);
	}
	
	
	
	
	return tab;
}































