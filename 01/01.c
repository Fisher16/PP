//Mikolaj Koszowski

#include <stdio.h>

int main(void){
	char nazwa[16];
	printf("Podaj nazwe pliku: ");
	scanf("%s", nazwa);
	puts("");
	
	FILE *plik=fopen(nazwa,"r");
	
	if(!plik)
	{
		printf("nie dziala %s /n", nazwa);
		return 1;
	}
	puts("******************************************************************************");
	printf("| Lp. | Nr albumu | Nazwisko        | Imie            | Grupa | Wiek | Uwagi |\n");
	int album,rok,lp=1;
	char nazwisko[32], imie[32], grupa[16];
	while(fscanf(plik,"%d %s %s %s %d", &album, nazwisko, imie, grupa, &rok)!=EOF)
	{
		int wiek=2016-rok;
		printf("| %3d |    %06d | %-16s| %-16s| %-5s | %4d |", lp,album,nazwisko,imie,grupa,wiek);
		if((2016-rok)>26)
		{
			printf("  ZUS  |\n");
		}
		else if(album<1000)
		{
			printf("  !PL  |\n");
		}
		else puts("       |");
		lp +=1;
	}	
	
	puts("******************************************************************************");
	puts("");
	return 0;
	}
