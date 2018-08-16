#include<stdio.h>
int main()
{
	int ti,t;
	scanf("%d",&t);
	for(ti=0; ti<t; ti++)
	{
		long long n;
		scanf("%lld",&n);
	
		printf("%lld\n",(((3*n*(n+1))/2)-n)%1000007);		
	}
	return 0;
}
