#include<stdio.h>
#include<limits.h>

int main()
{
	int t,ti;
	scanf("%d",&t);
	for(ti=0; ti<t; ti++)
	{
		int q,qi;
		scanf("%d",&q);
		int a[1000000]={0}, b[1000000]={0}, ia=-1, ib=-1;
		long long int sum=0;
		for(qi=0; qi<q; qi++)
		{
			int x,y;
			scanf("%d",&x);

			if(x==1)
			{
				scanf("%d",&y);
				sum+=y;
				ia++;
				a[ia]=y;
				if(ib==-1 || b[ib] > y){ ib++; b[ib]=y;}
			}

			else if(x==2)
			{
				if(ia>=0)
				{
					sum=sum-a[ia];
					if(a[ia]==b[ib]) ia--, ib--;
					else ia--;
				}
				else
				{
					b[0]=INT_MAX;
				}
			}
			if(ia==-1) printf("-1 0\n");
			else printf("%d %lld\n",b[ib], sum);
		}
	}
	return 0;
}
