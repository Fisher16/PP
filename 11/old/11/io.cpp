#include "arg.h"
#include "io.h"
#include <stdlib.h>
#include <stdint.h>

sygnal wczytaj_dane (const opcje_programu &op){
sygnal tab={NULL,NULL,0};
if(op.rdzp==BINARNY){

    FILE *plik=fopen(op.we,"rb");
    if(!plik){
        puts("Error");
        exit(0);
    }

    int32_t  n;
    fread(&n,sizeof(int32_t),1,plik);
    bool dlugie=false;
    if(n<0)dlugie=true;
    n<<=1;
    n>>=1;
    tab.rozm=(int)n;
	printf("%d\n",tab.rozm);
    tab.x=(double*)malloc(sizeof(double)*tab.rozm);
    tab.y=(double*)malloc(sizeof(double)*tab.rozm);
    double* tablicad;
    float* tablicaf;
    if(dlugie)tablicad=(double*)malloc(sizeof(double)*tab.rozm*2);
    else tablicaf=(float*)malloc(sizeof(float)*tab.rozm*2);


    if(dlugie)fread(tablicad,sizeof(double),2*tab.rozm,plik);
    else fread(tablicaf,sizeof(float),2*tab.rozm,plik);
    if(dlugie)for(int i=0;i<tab.rozm;i++){
       *(tab.x+i)=*(tablicad+2*i);
       *(tab.y+i)=*(tablicad+2*i+1);
    }
    else for(int i=0;i<tab.rozm;i++){
       *(tab.x+i)=*(tablicaf+2*i);
       *(tab.y+i)=*(tablicaf+2*i+1);
    }




}
if(op.rdzp==TEKSTOWY){
    FILE *plik=fopen(op.we,"r");
    if(!plik){
        puts("Error");
        exit(0);
    }

        double buforx,bufory;
       while(fscanf(plik,"%lf%lf",&buforx,&bufory)!=EOF){
            tab.x=(double*)realloc(tab.x,sizeof(double)*(tab.rozm+1));
            tab.y=(double*)realloc(tab.y,sizeof(double)*(tab.rozm+1));
            *(tab.x+tab.rozm)=buforx;
            *(tab.y+tab.rozm)=bufory;
            tab.rozm++;
        }


    }
return tab;
}
void binprint(void){
FILE *plik=fopen("dane_f_czysty.dat","rb");
    if(!plik){
        puts("Error");
        exit(0);
    }

    int32_t  n;
    fread(&n,sizeof(int32_t),1,plik);
    for(int i=0;i<1000;i++){
    float tab[2];
    fread(tab,sizeof(float),2,plik);
    printf("%f\t%f\n",tab[0],tab[1]);
    }



}


void zapisz_dane (const opcje_programu &op,const sygnal &dane){
FILE *plik=fopen(op.wy,"w");
double *wskx=dane.x,*wsky=dane.y;
for(int i=0;i<dane.rozm;i++){
    fprintf(plik,"%lf\t%lf\n",*wskx,*wsky);
    wskx++;
    wsky++;
}
fclose(plik);
}
