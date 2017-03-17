#include "arg.h"
#include "io.h"
#include <stdlib.h>
#include <time.h>
int main (int argc, char* arg[]){
opcje_programu opt=analizuj_opcje_programu (argc,arg);
printf("%d in=%s out=%s option=%d graf=%d\n",opt.rdzp,opt.we,opt.wy,opt.rdzo,opt.graf);
//binprint();
sygnal dane=wczytaj_dane(opt);
zapisz_dane(opt,dane);

return 0;
}
