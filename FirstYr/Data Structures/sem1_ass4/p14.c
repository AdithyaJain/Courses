#include<stdio.h>
#include<math.h>
#define PI 3.142

int main()
{
	int t,ti,n;
	scanf("%d",&t);
	for(ti=0; ti<t; ti++)
	{
		float x,acc;
		scanf("%f%f",&x,&acc);
		x=(x*PI)/180.0;
		float actsin=sin(x),term,mysin,denom;

		term=x;
		mysin=term;
		n=1;
		do
		{
			denom=2*n*(2*n+1);
			term=(-term*x*x)/denom;
			mysin=mysin+term;
			n++;
		}
		while(acc<=fabs(actsin-mysin));
		printf("%f\n",mysin);
	}
	return 0;
}
