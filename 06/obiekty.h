#ifndef _obiekty_h_
#define _obiekty_h_


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

double silaspr(const sprezyna &s);

double energia(const masapunktowa &m);

double energia(const sprezyna &s);



#endif
