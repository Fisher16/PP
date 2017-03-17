#include <stdio.h>
#include <stdlib.h>

int fac(int n)
{
return(n==1?n:n*fac(n-1));
}

int main(void)
{
int n;
scanf("%d",&n);
printf("%d\n",fac(n));

return 0;
}
