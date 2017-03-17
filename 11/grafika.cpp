#include "grafika.h"

void utworz_okno (int szerokosc, int wysokosc, const char *tytul)
{
	allegro_init ();
	install_keyboard ();
	set_color_depth (32);
	set_gfx_mode (GFX_AUTODETECT_WINDOWED, szerokosc, wysokosc, 0, 0);
	set_window_title (tytul);
	
	
}


void zakoncz (void)
{
	allegro_exit ();
}

void rysuj_okno (BITMAP *ekran, int kolor_tla, int kk){
	clear_to_color(screen, kolor_tla);
	line(ekran, 0, 300, 600, 300, kk);
	line(ekran, 300, 0, 300, 600, kk);
	for(int i=0;i<600;i+=6)for(int j=0;j<3;j++)putpixel(ekran,150,i+j,kk);
	for(int i=0;i<600;i+=6)for(int j=0;j<3;j++)putpixel(ekran,450,i+j,kk);
	for(int i=0;i<600;i+=6)for(int j=0;j<3;j++)putpixel(ekran,i+j,150,kk);
	for(int i=0;i<600;i+=6)for(int j=0;j<3;j++)putpixel(ekran,i+j,450,kk);
}

void rysuj_wykres (BITMAP *ekran, const sygnal &dane, int kk){
	for(int i=0;i<dane.rozm-1;i++){
		line(ekran, 300*(dane.x[i]+1), 300*(1-dane.y[i]),300*(dane.x[i+1]+1),300*(1-dane.y[i+1]), kk);
	}
	
	
	
	
}




