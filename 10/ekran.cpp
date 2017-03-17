#include "ekran.h"
#include <stdlib.h>

void rysuj_ramke (size_t szerokosc, size_t wysokosc){
	size_t x,y;
	
	for(x=0;x<szerokosc+1;x++){
		mvaddch(0,x,'#');
		mvaddch(wysokosc,x,'#');
	}
	for(y=0;y<wysokosc+1;y++){
		mvaddch(y,0,'#');
		mvaddch(y,szerokosc,'#');
	}
	
	
}

void rysuj_plansze (const postac *bohater, const postac *lista, size_t szerokosc, size_t wysokosc){
	rysuj_ramke(szerokosc,wysokosc);
	mvaddch(bohater->y,bohater->x,'+');
	while(lista){
		mvaddch(lista->y,lista->x,lista->stat?'O':'X');
		lista=lista->next;
	}
	refresh();

}
