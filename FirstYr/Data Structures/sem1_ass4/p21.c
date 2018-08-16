#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,i,m;
	scanf("%d%d",&n,&m);
	long long q,qi;
	scanf("%lld",&q);
	int store[60][2];
	int addidx=0;
	int dist;
	int mx,my;
	for(qi=0; qi<q; qi++)
	{
		char f[10];		
		scanf("%s",f);
		int x,y;
		scanf("%d%d",&x,&y);

		if(f[0]=='A')
		{
			store[addidx][0]=x;
			store[addidx][1]=y;
			addidx++;
		}
		else if(f[0]=='F')
		{
			if(addidx==0) printf("-1 -1\n");
			else
			{
				dist=abs(x-store[0][0])+abs(y-store[0][1]);
				mx=store[0][0];
				my=store[0][1];
				for(i=1; i<addidx; i++)
				{
					if(dist>(abs(x-store[i][0])+abs(y-store[i][1])))
					{
						dist=abs(x-store[i][0])+abs(y-store[i][1]);
						mx=store[i][0];
						my=store[i][1];
					}
					else if(dist==abs(x-store[i][0])+abs(y-store[i][1]))
					{
						if(store[i][0]<mx) mx=store[i][0],my=store[i][1];
						else if(store[i][0]==mx) if(store[i][1]<my) my=store[i][1];
					}
				}
				printf("%d %d\n",mx,my);
			}
		}
	}
	//	for(i=0; i<addidx; i++)printf("%d %d\n",store[i][0],store[i][1]);
	return 0;
}
