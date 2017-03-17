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

