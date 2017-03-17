//Mikolaj Koszowski

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main(void){
	
	bool koniec= true;
		
	while(koniec)
	{
		puts("\n\nMenu \n 0. Koniec \n 1. sin(x) \n 2. cos(x) \n 3. ln(1+x) \n");
		int wybor;
		scanf("%d", &wybor);
		
		
		float rez,w=0,x,c,x2;
		int n;
		switch(wybor)
		{
			
				case 1:
				n=2;
				puts("Żeby obliczyć sin(x) podaj x i rez");
				scanf("%f %f",&x,&rez);
				c=x;
				x2=(x*x);
				
				do{
					w+=c;
					c*=-x2/(n*(n+1));
					n+=2;
					
				}while(fabs(c)>rez);
				printf("\n Wynik: %f \n",w);
				
				break;
				
				case 2:
				n=1;
				puts("Żeby obliczyć cos(x) podaj x i rez");
				scanf("%f %f",&x,&rez);
				c=1;
				x2=(x*x);
				
				do{
					w+=c;
					c*=-x2/(n*(n+1));
					n+=2;
					
				}while(fabs(c)>rez);
				printf("\n Wynik: %f \n",w);
				
				
				break;
				
				case 3:
				n=1;
				puts("Żeby obliczyć ln(1+x) podaj x z zakresu [-1,1] i rez");
				scanf("%f %f",&x,&rez);
				if(fabs(x)>1)
				{
					puts("Zły przedział");
					break;
				}
				c=x;
								
				do{
					w+=c;
					c*=-x;
					c/=n;
					n++;
					
				}while(fabs(c)>rez);
				printf("\n Wynik: %f \n",w);
				
				
				
				break;
				
				case 0:
				koniec= false;
				break;
				default:
				puts("Brak opcji");
		}
	
	
}
	
	
	return 0;
	}
