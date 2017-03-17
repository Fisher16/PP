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
	
	
	
	
	for(int l=0;l<ile;l++){
		
		if(strchr(nazwiska[l],'e')!=strrchr(nazwiska[l],'e'))
		{
			printf("%-15s %-15s Eskulapa\n",nazwiska[l],imiona[l]);
			
		}
		else if(strchr(nazwiska[l],'o'))
		{
		if(*nazwiska[l]=='K' && *(nazwiska[l]+1)=='o')
		{
			printf("%-15s %-15s Kokoszka\n",nazwiska[l],imiona[l]);
			
		}
		else
		{
			printf("%-15s %-15s Orzel\n",nazwiska[l],imiona[l]);
			
		}
		}
		else if(strstr(nazwiska[l],"ski")+3==nazwiska[l]+strlen(nazwiska[l]) || strstr(nazwiska[l],"ska")+3==nazwiska[l]+strlen(nazwiska[l]))
		{
			printf("%-15s %-15s Lew\n",nazwiska[l],imiona[l]);
			
		}
		
		else printf("%-15s %-15s Kroliczek\n",nazwiska[l],imiona[l]);
			
	}
	
	for(int x=0;x<ile;x++)
	{
		free(nazwiska[x]);
		free(imiona[x]);
		
	}
	
	
	return 0;
	}
