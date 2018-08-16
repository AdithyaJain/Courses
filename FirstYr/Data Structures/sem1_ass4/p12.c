#include<stdio.h>
#include<math.h>


int  main(void)
{
	long long int n;
	scanf("%lld",&n);

	double i,j,isq,jsq;
	long long int count=0;

	for(i=1; i<n; i++)
	{
		isq=i*i;
		for(j=i+1; j<=n; j++)
		{
			jsq=j*j;
			if(sqrt(isq+jsq)==(int)sqrt(isq+jsq) && sqrt(isq+jsq)<=n) count++;
		}
	}
	printf("%lld\n",count);



	return 0;

}
