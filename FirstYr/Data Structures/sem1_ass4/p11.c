#include<stdio.h>

int main(void)
{
	long long int t,ti;
	scanf("%lld",&t);
	for(ti=0; ti<t; ti++)
	{
		long long int n,m,a,b;
		scanf("%lld%lld%lld%lld",&n,&m,&a,&b);

		if(((double)(b/m))<a)
		{
			long long int numofrides=n/m;
			long long int poss1=numofrides*b+a*(n-((n/m)*m));
			long long int poss2=(numofrides+1)*b;
			printf("%lld\n",(poss1<poss2)?poss1:poss2);
		}
		else printf("%lld\n",a*n);
	}
	return 0;
}
