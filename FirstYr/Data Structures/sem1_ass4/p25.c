#include<stdio.h>

long long powtwo(int n)
{
	int i;
	long long ans=1;
	for(i=0; i<n; i++) ans=ans*2;
	return ans;
}


void addone(int b[], int size)
{
	int i,firstzero;
	for(i=size-1; i>=0; i--)
		if(b[i]==0) {firstzero=i; break;}
	b[firstzero]=1;
	for(i=firstzero+1; i<size; i++) b[i]=0;
}

int main()
{
	int t,ti;
	scanf("%d",&t);
	for(ti=0; ti<t; ti++)
	{
		int n,j;
		long long i;
		scanf("%d",&n);
		long long a[n];
		for(i=0; i<n; i++) scanf("%lld",&a[i]);
		int b[n],rem;
		for(i=0; i<n; i++)
		{
			rem=a[i]%3;
			b[i]=rem;
		}

		int bin[n];
		for(i=0; i<n; i++) bin[i]=0;
		long long p=powtwo(n),count=0;
		

		for(i=0; i<p; i++)
		{
			int sum=0;
			for(j=0; j<n; j++) sum=sum+(b[j]*bin[j]);
//			printf("sum=%d\n",sum);
//			for(j=0; j<n; j++) printf("%d",bin[j]);
//			printf("\n");
			if(sum%3==0) count++;
			if(i<p-1) addone(bin, n);
		}
		printf("%lld\n",count-1);
	}
}
