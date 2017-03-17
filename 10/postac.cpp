#include "postac.h"
#include <stdlib.h>



postac *generuj_postacie (size_t szerokosc, size_t wysokosc, size_t n){
	postac* wsk;
	postac* biez=NULL;
	for(size_t i=0;i<n;i++){
		postac *nowa=new postac;
		nowa->x=(rand()%szerokosc)+1;
		nowa->y=(rand()%wysokosc)+1;		
		nowa->stat=true;
		
		if(biez)biez->next=nowa;
		else wsk=nowa;//tylko raz wsk=start
		biez=nowa;
	}
	biez->next=NULL;

return wsk;
}

void ruch_postaci (postac *lista, size_t szerokosc, size_t wysokosc){
	
	while(lista){
		size_t lx=(rand()%3)-1;
		size_t ly=(rand()%3)-1;
		if(lista->stat){
			if(lista->x + lx < szerokosc && lista->x + lx >0)lista->x+=lx;
			if(lista->y + ly < wysokosc && lista->y + ly >0)lista->y+=ly;
		}
		lista=lista->next;
	}

}

size_t ile_zywych (const postac *lista){
	size_t ile=0;
	while(lista){
		if(lista->stat)ile++;
		lista=lista->next;
	}
return ile;	
}

void lapanka (const postac *bohater,postac *lista){
	
	while(lista){
	if(bohater->x == lista->x && bohater->y == lista->y)lista->stat=false;
	lista=lista->next;
}
}

















