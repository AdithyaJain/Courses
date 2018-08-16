#include<stdio.h>

long long gcd(long long a, long long b)
{
	if(b%a!=0) gcd(b%a, a);
	else return a;
}


long long min(long long a, long long b)
{
	return (a>b)?b:a;
}
long long max(long long a, long long b)
{
	return (a>b)?a:b;
}
main()
{
	long long n,i;
	scanf("%lld",&n);
	long long a[n];

	for(i=0; i<n; i++) scanf("%lld",&a[i]);

	printf("%lld ",a[0]);

	for(i=0; i<(n-1); i++)
		printf("%lld ",(a[i]*a[i+1])/(gcd((min(a[i],a[i+1])),(max(a[i],a[i+1])))));
	printf("%lld\n",a[n-1]);
	return 0;
}


