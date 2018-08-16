#include<stdio.h>
#define MOD 1000000007
long long a,b,c,d;

void fib(long long n, long long ans[])
{
	if(n==0){ ans[0]=0; ans[1]=1; return;}

	fib(n/2, ans);
	a=ans[0];
	b=ans[1];
	
	c=2*b-a;
	if(c<0) c+=MOD;
	c=(a*c)%MOD;
	
	d=(a*a+b*b)%MOD;

	if(n%2==0) ans[0]=c, ans[1]=d;
	else ans[0]=d, ans[1]=c+d;
}

int main()
{
	long long n,i,q,j;
	scanf("%lld%lld",&n,&q);
	long long a[n+1],sum=0,ans[2]={0}, x,y;
	for(i=1; i<=n; i++) scanf("%lld",&a[i]);
	
	for(i=1; i<=n; i++){ fib(a[i]+1, ans); sum=(sum+ans[0])%MOD;}

	for(j=0; j<q; j++)
	{
		scanf("%lld%lld",&x,&y);
		
		fib(a[x]+1, ans);
		sum=(sum-ans[0]);
		if(sum<0) sum+=MOD;
		a[x]+=y;
		fib(a[x]+1,ans);
		sum=(sum+ans[0])%MOD;
		
		printf("%lld\n",sum);
	}
	return 0;
}
