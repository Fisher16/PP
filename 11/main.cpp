#include "arg.h"
#include "io.h"
#include <stdlib.h>
#include <time.h>
#include "sygnal.h"
#include "grafika.h"
#include <allegro.h>



int main (int argc, char* arg[]){
opcje_programu opt=analizuj_opcje_programu (argc,arg);
printf("%d in=%s out=%s option=%d graf=%d\n",opt.rdzp,opt.we,opt.wy,opt.rdzo,opt.graf);
//binprint();
sygnal dane=wczytaj_dane(opt);
zapisz_dane(opt,dane);
sygnal wynik={NULL,NULL,0};
if(opt.rdzo==0)wynik=wygladz(dane);
if(opt.rdzo==1)wynik=pochodna(dane);
if(opt.rdzo==2)wynik=calka(dane);
zapisz_dane(opt,wynik);

if(opt.graf){
	
	sygnal wyjscie=normalizuj(wynik);
	dane.rozm-=2;
	sygnal wejscie=normalizuj(dane);
	if(opt.rdzo==1 || opt.rdzo==2){
		for(int i=0;i<wyjscie.rozm;i++)wyjscie.y[i]=0.5*wyjscie.y[i]+0.5;
		for(int i=0;i<wejscie.rozm;i++)wejscie.y[i]=0.5*wejscie.y[i]-0.5;
		puts("test");
		
	}
	int x=600;
	utworz_okno(x,x,"Oscyloskop");
	rysuj_okno(screen,makecol(150,150,50),makecol(0,0,0));
	rysuj_wykres(screen,wyjscie,makecol(255,0,0));
	if(opt.rdzo==1 || opt.rdzo==2)rysuj_wykres(screen,wejscie,makecol(255,0,0));
	
	readkey();
	
}
//zapisz_dane(opt,wyjscie);
printf("Max y %lf x %lf\nMin y %lf x %lf\n",mx(dane.y,dane.rozm),mx(dane.x,dane.rozm),mn(dane.y,dane.rozm),mn(dane.x,dane.rozm));



free(dane.x);
free(dane.y);
free(wynik.x);
free(wynik.y);

return 0;
}
