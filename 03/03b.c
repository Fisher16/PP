//Mikolaj Koszowski

#include <stdio.h>
#include <stdbool.h>


int main(void){
	const short wsp[]={1,10,3,30,9,90,27,76,81,34,49,5,50,15,53,45,62,38,89,17,73,51,25,56,75,71,31,19,93,57};
	int tab[30];
	int i=0;
	printf("Podaj NRB: ");
	while(i<26)
	{
	int a=getchar();
		if(a>='0' && a<='9')
		{
			tab[i]=(int)a-48;
			i++;
			
		}
	}
	tab[28]=tab[0];
	tab[29]=tab[1];
	int *wskz=tab;
	for(int j=0;j<26;j++)
	{
	*wskz=*(wskz+2);
	wskz ++;
	}
	tab[27]=1;
	tab[26]=2;
	tab[25]=5;
	tab[24]=2;
	
	int suma=0;
	const short *wsk=wsp;
	wskz+=3;
	//printf("%d",wskz-tab);
	for(int l=0;l<30;l++)
	{
		suma+=*wsk * *wskz;
		wsk++;
		wskz--;
		
	}
		//wsp[l]*tab[29-l];
	
	if(suma%97==1)printf("Poprawny  numer\n");
	else printf("Zly numer\n");
	
	FILE *plik=fopen("dane.txt","r");

	int bank;
	int test=tab[3]+10*tab[2]+100*tab[1]+1000*tab[0];
	while(!feof(plik))
	{
		fscanf(plik,"%d",&bank);
		char nazwa[30];
		fgets(nazwa,30,plik);
		if(bank==test)
		{
			printf("Nazwa banku %s \n",nazwa);
			break;
		}
	}
	//puts("");
	//for(int k=0;k<30;k++)printf("%d",tab[k]);

	return 0;
	}
