#include<stdio.h>
#include<limits.h>

long long path[510][510];

int main()
{
	int n,m,i,j,k;
	scanf("%d%d",&n,&m);
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
		{
			if(i == j) path[i][j] = 0;
			else path[i][j] = INT_MAX;
		}

	for(i=0; i<m; i++)
	{
		long long u,v,w;	
		scanf("%lld%lld%lld",&u, &v, &w);
		if(path[u][v] != INT_MAX)
		{
			if(path[u][v] < w)
				path[u][v] = path[v][u] = w;
		}
		else
		{
			path[u][v] = w;
			path[v][u] = w;
		}
	}
	
	for(k=1; k<=n; k++)
		for(i=1; i<=n; i++)
			for(j=1; j<=n; j++)
			{
				if(path[i][j] > path[i][k] + path[k][j]) path[i][j] = path[i][k] + path[k][j];
			}
	long long sum = 0;
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++) sum+=path[i][j];
	printf("%lld\n",sum);
}
