#include<stdio.h>

int main()
{
	int t,ti;
	scanf("%d",&t);
	for(ti=0; ti<t; ti++)
	{
		long long a[20001],i,n;
		scanf("%lld",&n);
		a[0]=1;
		a[1]=1;
		
		for(i=2; i<20001; i++)
		{
			a[i]=(a[i-1]+a[i-2])%n;
		}
//		for(i=0; i<100; i++) printf("%lld\n",a[i]);
		long long per,start;
		int flag;	
		for(per=2; per<20001; per++)
		{
			for(start=0; start<per; start++)
			{
				for(i=0; i<((20001-start)/per); i++)
				{
					if(a[start]==a[start+(i*per)]) flag=1;
					else { flag=0; break; }
				}
				if(flag==0) break;
			}
			if(flag==1) break;
		}
		if(flag==1 && per<=10000) printf("%lld\n",per);
		else printf("-1\n");

	}
	return 0;
}
