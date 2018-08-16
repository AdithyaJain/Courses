#include <stdio.h>
#define SIZE 100000

long long int memo[SIZE];

long long int fib(int n)
{
	//base case
	if(n==1 || n==2) return 1;

	if(memo[n] != 0) return memo[n];
	else
	{
		memo[n] = fib(n-1) + fib(n-2);
		return memo[n];
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	int i;
	for(i=1; i<=n; i++) memo[i] = 0;
	printf("%lld\n",fib(n));
	return 0;
}

