#include<stdio.h>

int main()
{
	int t,ti;
	scanf("%d",&t);
	for(ti=0; ti<t; ti++)
	{
		long long p,q;
		scanf("%lld%lld",&p,&q);

		int n,i;
		scanf("%d",&n);
		long long a[90]={0},b[90]={0},rem;
		for(i=0; i<n; i++) scanf("%lld",&a[i]);

		if(n==1)
		{
			if(a[0]==(p/q) && p%q==0) printf("YES\n");
			else printf("NO\n");
		}	
		else
		{
			int flag=1;
			for(i=0; i<90 && p%q!=0; i++)
			{
				b[i]=p/q;
				rem=p%q;
				p=q;
				q=rem;
			}
			b[i]=p/q;
			if(a[n-1]==1)
			{
				b[n-1]=1;
				b[n-2]--;
			}
//			if(i==n-1 && rem==0) flag=1;
//			else flag=0;
			
			for(i=0; i<n; i++)
			{
				if(a[i]!=b[i])
				{
					flag=0;
					break;
				}
			}
			if(flag==1) printf("YES\n");
			else if(flag==0) printf("NO\n");
		}

	}
	return 0;
}
