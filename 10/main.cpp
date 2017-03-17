#include "ekran.h"
#include "postac.h"
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
int main ()
{
srand(time(NULL));
size_t szer,wys,n;
scanf("%zu %zu %zu",&szer,&wys,&n);
szer++;
wys++;
postac* postacie = generuj_postacie(szer,wys,n);
postac bohater={true,szer/2,wys/2,NULL};
/*
while(postacie){
printf("X:%zu Y:%zu address: %p next: %p\n",postacie->x,postacie->y,(void*)postacie,(void*)postacie->next);
postacie=postacie->next;
}
*/
curs_set(0);
initscr ();
noecho ();
cbreak ();
keypad (stdscr, TRUE);
bool end=false;
while(ile_zywych(postacie)&& !end){
	clear();
	curs_set(0);
	rysuj_plansze(&bohater,postacie,szer,wys);
	lapanka(&bohater,postacie);
	ruch_postaci(postacie,szer,wys);
	switch ( getch () ) {
		case KEY_UP:
		bohater.y-=1;
		break;
		
		case KEY_DOWN:
		bohater.y+=1;
		break;
		
		case KEY_LEFT:
		bohater.x-=1;
		break;
		
		case KEY_RIGHT:
		bohater.x+=1;
		break;
		
		case 27:
		clear();
		end=true;
		break;
}
}
endwin();
return 0;
}
