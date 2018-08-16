#include<stdio.h>

long long a[1000010]={0};
long long stack[1000010]={0};

long long int f(long long int min, long long int secmin)
{
	return ((min|secmin)*(min|secmin))-((min&secmin)*(min&secmin));
}

int main()
{
	int t,ti;
	scanf("%d",&t);
	for(ti=0; ti<t; ti++)
	{
		int n;
		scanf("%d",&n);
		int i;
		for(i=0; i<n; i++) {
			scanf("%lld",&a[i]);
		}
		if(n==1) printf("0\n");
		else
		{
			long long int idx=-1, max;
			stack[0]=a[0], idx=0, max=0;
			for(i=1; i<n; i++)
			{
				if(a[i]>=stack[idx])
				{
					idx++;
					stack[idx]=a[i];
				}
				else
				{
					while(a[i]<stack[idx] && idx>=0)
					{
						long long int check = f(a[i], stack[idx]);
						if(max<check) max=check;
						idx--;
					}
					idx++;
					stack[idx]=a[i];
				}
				if(idx>=1)
				{
					long long temp = f(stack[idx], stack[idx-1]);
					if(max<temp) max=temp;
				}
			}
			printf("%lld\n",max);
		}
	}
	return 0;
}
