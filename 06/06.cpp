//Mikolaj Koszowski
#include <math.h> 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct masapunktowa
{
	
	double masa;
	double x;
	double v;
	
};

struct sprezyna
{
	double dx;
	double k;
	masapunktowa *masa1;
	masapunktowa *masa2;
	
};

double silaspr(const sprezyna &s)
{

		return s.k*(s.masa2->x - s.masa1->x -s.dx);//s.masa1 jest wskaznikiem
	
}

double energia(const masapunktowa &m)
{
	
	return 0.5*m.masa*m.v*m.v;
	
}

double energia(const sprezyna &s)
{

	return 0.5*s.k*(s.masa2->x - s.masa1->x -s.dx)*(s.masa2->x - s.masa1->x -s.dx);

}
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
