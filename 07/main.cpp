#include "obiekty.cpp"
#include <math.h> 
#include <stdio.h>
#include <stdlib.h>



int main(){
	
	size_t rozmiar=0;
	
	Kapelusz *tab=wczytaj_dane(stdin,rozmiar);
	StatParam wynik=oblicz(tab,rozmiar);
	
	printf("Wys %f(%f)\nMasa %f\nObj %f\n",wynik.avh,wynik.uavh,wynik.masa,wynik.obj); 
	
	return 0;
}
