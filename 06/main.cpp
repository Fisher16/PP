//Mikolaj Koszowski

#include <stdio.h>
#include <stdlib.h>
#include "obiekty.h"

int main(){
double l=1, vo=0.5, k=200;

masapunktowa m1={10,0,0};
masapunktowa m2={2,l,vo};

sprezyna spr={l,k,&m1,&m2};

double dt=0.001;
for(double t=0;t<5.0;t+=dt)
{
		m2.x+=m2.v*dt;
		m2.v+=dt* -silaspr(spr)/m2.masa;
		m1.v+=dt* silaspr(spr)/m1.masa;
		m1.x+=m1.v*dt;
	
		printf("%.3lf \t %lf \t %lf \t %.2lf \n",t,m1.x,m2.x,energia(spr)+energia(m1)+energia(m2));
	
}


return 0;
}
