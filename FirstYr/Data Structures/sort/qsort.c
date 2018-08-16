#include<stdio.h>
#include<stdlib.h>

int cmpfunc (const void * a, const void * b)
{
	   return ( *(int*)a - *(int*)b );
}

int main()
{
	int n,i;
	scanf("%d",&n);
	int c[n];
	for(i=0; i<n; i++) scanf("%d",&c[i]);

	qsort(c, n, sizeof(int), cmpfunc);
	for(i=0; i<n; i++) printf("%d",c[i]);
}
