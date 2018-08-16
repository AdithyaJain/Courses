#include<stdio.h>

#define MAX 1000
void multiply(long long int a[], long long int n)
{
	long long int i,carry=0;
	for(i=999; i>=0; i--)
	{
		long long mult=a[i]*n+carry;
		a[i]=mult%10;
		carry=mult/10;
	}
}

int main()
{
	long long int n,i;
	scanf("%lld",&n);
	long long int a[MAX]={0};
	a[999]=1;
	for(i=1; i<=n; i++) multiply(a, i);

	for(i=0; i<1000; i++) if(a[i]!=0) break;
	int j;
	for(j=i; j<1000; j++) printf("%lld",a[j]);
	printf("\n");
	return 0;
}
