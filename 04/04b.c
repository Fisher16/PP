//Mikolaj Koszowski

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	int ile;
	scanf("%d",&ile);
	char *nazwiska[ile];
	char *imiona[ile];
	for(int i=0;i<ile;i++){
		char bn[65],bi[65];
		scanf("%s %s",bn,bi);
		nazwiska[i]=(char*)calloc(sizeof(char),strlen(bn)+1);
		imiona[i]=(char*)calloc(sizeof(char),strlen(bi)+1);
		strcpy(nazwiska[i],bn);
		strcpy(imiona[i],bi);
		
	}
	
	for(int j=0;j<ile-1;j++){
		for(int k=0;k<ile-j-1;k++){
			
			if(strcmp(nazwiska[k],nazwiska[k+1])>0){
				char *bna,*bim;
				bna=nazwiska[k];
				bim=imiona[k];
				nazwiska[k]=nazwiska[k+1];
				imiona[k]=imiona[k+1];
				nazwiska[k+1]=bna;
				imiona[k+1]=bim;
				
			}
	
		}

	}
	
	
	//for(int x=0;x<ile;x++)printf("%s %s \n",nazwiska[x],imiona[x]);
	
	for(int l=0;l<ile;l++){
		int a=0;
		if(strchr(nazwiska[l],'e')!=strrchr(nazwiska[l],'e'))
		{
			printf("%s %s Eskulapa\n",nazwiska[l],imiona[l]);
			a=1;
		}
		if(strchr(nazwiska[l],'o'))
		{
		if(*nazwiska[l]=='K' && *(nazwiska[l]+1)=='o')
		{
			printf("%s %s Kokoszka\n",nazwiska[l],imiona[l]);
			a=1;
		}
		else
		{
			printf("%s %s Orzel\n",nazwiska[l],imiona[l]);
			a=1;
		}
		}
		if(strstr(nazwiska[l],"ski")+3==nazwiska[l]+strlen(nazwiska[l]) || strstr(nazwiska[l],"ska")+3==nazwiska[l]+strlen(nazwiska[l]))
		{
			printf("%s %s Lew\n",nazwiska[l],imiona[l]);
			a=1;
		}
		
		if(!a)printf("%s %s Kroliczek\n",nazwiska[l],imiona[l]);
			
	}
	
	return 0;
	}
