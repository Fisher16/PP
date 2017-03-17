#include "arg.h"
#include "io.h"
#include <stdlib.h>
#include <string.h>

opcje_programu analizuj_opcje_programu (int argc, char *arg[]){
	bool typ=false,out=false,par=false;
	opcje_programu tab;
	tab.graf=false;
	for(int i=0;i<argc;i++){
		if(!strcmp("-b",arg[i])){
			tab.rdzp=BINARNY;
			typ=true;
			strcpy(tab.we,arg[i+1]);
		}
		if(!strcmp("-t",arg[i])){
			tab.rdzp=TEKSTOWY;
			typ=true;
			strcpy(tab.we,arg[i+1]);
		}
		if(!strcmp("-o",arg[i])){
			out=true;
			strcpy(tab.wy,arg[i+1]);
		}
		if(!strcmp("-s",arg[i])){
			par=true;
			tab.rdzo=SOPT;
		}
		if(!strcmp("-d",arg[i])){
			par=true;
			tab.rdzo=DOPT;
		}
		if(!strcmp("-i",arg[i])){
			par=true;
			tab.rdzo=IOPT;
		}
		if(!strcmp("-p",arg[i])){
			par=true;
			tab.rdzo=POPT;
		}
		if(!strcmp("-g",arg[i])){
			tab.graf=true;
		}

	}


	if(!(par&&out&&typ)){
		puts("Podano zle argumenty");
		exit(0);
	}


	return tab;
}
