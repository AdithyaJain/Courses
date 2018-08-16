#include<stdio.h>

main(void)
{
	long long t,ti;
	scanf("%lld",&t);
	for(ti=0; ti<t; ti++)
	{
		long long n;
		scanf("%lld",&n);
		long long int a[n+1],i;
		for(i=0; i<n; i++) scanf("%lld",&a[i]);
		a[n]=0;

		long long sumr=0,suml=0,flag=0;
		for(i=1; i<n; i++) suml=suml+a[i];
//		printf("sumr=%lld\tsuml=%lld\n",sumr,suml);

		for(i=0; i<n-1; i++)
		{
			if(sumr==suml) {printf("YES\n"); flag=1; break;}
			else
			{
				sumr=sumr+a[i];
				suml=suml-a[i+1];
			}
//		printf("sumr=%lld\tsuml=%lld\n",sumr,suml);
		}
		if(sumr==0) {printf("YES\n"); flag=1;}
		if(flag==0) printf("NO\n");

	}
	return 0;
}
