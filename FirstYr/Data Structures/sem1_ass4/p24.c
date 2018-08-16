#include<stdio.h>
#include<limits.h>

int smoke(int p[], int n)
{

	int m[n][n],new[n][n];

	int i,j,k,L,smoke;

	for(i=0; i<n; i++)
		m[i][i] = 0, new[i][i]=p[i];


	for(L=2; L<=n; L++)
	{
		for(i=0; i<n-L+1; i++)
		{
			j=i+L-1;
			m[i][j]=INT_MAX;
			for(k=i; k<j; k++)
			{
				smoke=m[i][k]+m[k+1][j]+new[i][k]*new[k+1][j];
				if(smoke<m[i][j])
				{
					m[i][j]=smoke;
					new[i][j]=(new[i][k]+new[k+1][j])%100;
				}
			}
		}
	}
	return m[0][n-1];
}

int main()
{
	int t,ti;
	scanf("%d",&t);
	for(ti=0; ti<t; ti++)
	{
		int n;
		scanf("%d",&n);
		int a[n],i;
		for(i=0; i<n; i++) scanf("%d",&a[i]);
		printf("%d\n",smoke(a,n));
	}
	return 0;
}
