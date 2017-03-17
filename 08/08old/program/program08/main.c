#include <stdio.h>
#include <stdint.h>
#include "grafika.h"
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

struct atom{

	int x;
	int y;
	int kol;
	float czas;
	bool onoff;
};

struct atom* gen(int szer,int wys,int ilosc, const int kolor[], const float lambda[]){
	struct atom* tabprime=(struct atom*)malloc(sizeof(struct atom)*szer*wys);
	struct atom*tab=tabprime;
	for(int x=0;x<szer;x++){
		for(int y=0;y<wys;y++){
			int los=rand()%ilosc;
			tab->kol=kolor[los];
			tab->czas=lambda[los];
			tab->x=x;
			tab->y=y;
			tab->onoff=true;
			tab++;
		}
	}



	return tabprime;
}


int main (int argc, char *arg[])
{

	if(argc!=2){
		puts("Blad");
		exit (1);

	}

	FILE *plik=fopen(arg[1],"rb");
	if(!plik){
		puts("Error");
		return 1;
	}
	uint16_t szer,wys;
	uint8_t ilosc;
    int rozm;
	rozm=fread(&szer,sizeof(uint16_t),1,plik);
	rozm=fread(&wys,sizeof(uint16_t),1,plik);
	rozm=fread(&ilosc,sizeof(uint8_t),1,plik);

	utworz_okno(szer,wys,"Okno");
	printf("Szer %u Wys %u Liczba at %u\n",szer,wys,ilosc);

	float lambda[ilosc];
	int kolor[ilosc];

	for(int i=0;i<ilosc;i++){
		rozm=fread(&lambda[i],sizeof(float),1,plik);
		uint8_t tab[4];
		rozm=fread(tab,sizeof(uint8_t),4,plik);
		kolor[i]=makecol(tab[1],tab[2],tab[3]);
		fprintf(stderr,"%d\t%d\t%d\n", tab[1],tab[2],tab[3]);
	}

	for(int i=0;i<ilosc;i++)fprintf(stderr,"Atom %d lambda %f  kolor %d\n", i+1,lambda[i],kolor[i]);


	srand(time(NULL));
    rozm=(int)szer*wys;
	struct atom* atomy=gen(szer,wys,ilosc,kolor,lambda);
	for(int i=0;i<(szer*wys);i++){
		putpixel(screen,atomy->x,atomy->y,atomy->kol);
		//printf("%f\n",atomy->czas);
		atomy++;
	}
    readkey();
	int n=0;
	double dt=0.00001;
	while(n<rozm*0.85){
	int ran=rand()%(rozm+1);
	atomy-=ran;
	if(atomy->onoff&&((double)rand()/RAND_MAX)<atomy->czas*dt){
        putpixel(screen,atomy->x,atomy->y,0);
        n++;
        printf("%f\t%d\n",dt,rozm-n);
        rest(150);
        atomy->onoff=false;
    }
    dt+=0.00001;
    atomy+=ran;
	}

	readkey();
	zakoncz();

	return 0;
}
