#ifndef _ekran_h_
#define _ekran_h_
#include <stdlib.h>
#include <ncurses.h>
#include "postac.h"
void rysuj_ramke (size_t szerokosc, size_t wysokosc);

void rysuj_plansze (const postac *bohater, const postac *lista, size_t szerokosc, size_t wysokosc);

#endif
