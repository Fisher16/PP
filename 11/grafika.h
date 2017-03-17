#ifndef _grafika_h_
#define _grafika_h_
#include "arg.h"
#include "io.h"

#include <allegro.h>

// Uruchamia tryb graficzny
void utworz_okno (int szerokosc, int wysokosc, const char *tytul);

// Zamyka tryb graficzny
void zakoncz (void);

void rysuj_okno (BITMAP *ekran, int kolor_tla, int kk);
void rysuj_wykres (BITMAP *ekran, const sygnal &dane, int kk);
#endif
