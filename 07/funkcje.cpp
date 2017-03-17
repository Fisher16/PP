#include "obiekty.cpp"
#include <math.h> 
#include <stdio.h>
#include <stdlib.h>


Kapelusz *wczytaj_dane(FILE *we, size_t &rozmiar){
	Kapelusz *kap=NULL;
	rozmiar=0;
	char bufor[2];
	
	while(fscanf(we,"%s",bufor)!=EOF){
		kap=(Kapelusz*)realloc(kap,sizeof(Kapelusz)*(rozmiar+1));
		
		if(bufor[0]=='W'){
		fscanf(we,"%f%f%f",&kap[rozmiar].kape.wa.m,&kap[rozmiar].kape.pr.h,&kap[rozmiar].kape.wa.r);
		kap[rozmiar].k=KOLO;
		}
		
		if(bufor[0]=='P'){
		fscanf(we,"%f%f%f%f",&kap[rozmiar].kape.pr.m,&kap[rozmiar].kape.wa.h,&kap[rozmiar].kape.pr.a,&kap[rozmiar].kape.pr.b);
		kap[rozmiar].k=KWADRAT;
	
		}
		if(bufor[0]=='T'){
		fscanf(we,"%f%f%f",&kap[rozmiar].kape.tr.m,&kap[rozmiar].kape.tr.h,&kap[rozmiar].kape.tr.a);
		kap[rozmiar].k=TROJKAT;
		}
		
		
	rozmiar++;
	}
	
	return kap;
}

StatParam oblicz(const Kapelusz *tk, size_t n){
	StatParam stat={0,0,0,0};
	for(size_t i=0;i<n;i++){
		
	//stat.avh+=tk[i].kape.
	
	if(tk[i].k==KOLO)stat.obj+=tk[i].kape.wa.r * tk[i].kape.wa.r * 3.1416 * tk[i].kape.wa.h;
	if(tk[i].k==KWADRAT)stat.obj+=tk[i].kape.pr.a * tk[i].kape.pr.b * tk[i].kape.pr.h;
	if(tk[i].k==TROJKAT)stat.obj+=tk[i].kape.tr.a * tk[i].kape.tr.a * sqrt(3) * tk[i].kape.tr.h /4;
		
	stat.avh+=tk[i].kape.wa.h;
	stat.masa+=tk[i].kape.wa.m;
	
}
	stat.avh/=n;
	
	for(size_t i=0;i<n;i++){
		stat.uavh+=(stat.avh-tk[i].kape.wa.h)*(stat.avh-tk[i].kape.wa.h);
	}
	stat.uavh=sqrt(stat.uavh / n);
	return stat;
}
