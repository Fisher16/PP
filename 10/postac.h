#ifndef _postac_h_
#define _postac_h_
#include <stdlib.h>
struct postac{
	bool stat;
	size_t x;
	size_t y;
	postac* next;
	
};
void lapanka (const postac *bohater,postac *lista);
postac *generuj_postacie (size_t szerokosc, size_t wysokosc, size_t n);

void ruch_postaci (postac *lista, size_t szerokosc, size_t wysokosc);

size_t ile_zywych (const postac *lista);


#endif
