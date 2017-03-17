#include <stdio.h>
#include "obiekty.h"

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
