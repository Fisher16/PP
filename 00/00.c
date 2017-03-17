//Mikolaj Koszowski

#include <stdio.h>

int main(void){
	char c;
	scanf("%c", &c);
	int b=(int) c;
	printf("ASCII %d \n", b);
	printf ("Rozmiar typu double = %zu\n", sizeof (double));

	for(int i=0;i<=25;i++){
		char f=(char) i+65;
		printf("%c \n", f);
		}
	printf("/n");
	
	return 0;
	}
