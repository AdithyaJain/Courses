#include<stdio.h>
#include<stdlib.h>

int lis(int y[], int n)
{
	int *lis, i,j,max=0;
	lis=(int*)malloc(n*sizeof(int));
	for(i=0; i<n; i++) lis[i]=1;

	for(i=0; i<n; i++)
		for(j=0; j<i; j++)
			if(y[i]>=y[j] && lis[i]<lis[j]+1) lis[i]=lis[j]+1;
	for(i=0; i<n; i++) if(max<lis[i]) max=lis[i];

	free(lis);
	return max;
}

int main()
{
	int t,ti,y[1000];
	double x[1000];
	scanf("%d",&t);
	for(ti=0; ti<t; ti++)
	{
		int n,m,i,j,max=0;
		scanf("%d%d",&n,&m);
		for(i=0; i<n; i++) scanf("%lf%d",&x[i],&y[i]);
//		for(i=0; i<n; i++) printf("%d\t",y[i]);
		printf("%d\n",n-lis(y,n));
	}
	return 0;
}
