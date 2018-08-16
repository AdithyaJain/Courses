#include<stdio.h>

long long int minimum(long long int a, long long int b, long long int c)
{
	if(a<=b && b<=c) return 1;
	if(a<=c && c<=b) return 1;
	if(b<=a && a<=c) return 2;
	if(b<=c && c<=a) return 2;
	if(c<=a && a<=b) return 3;
	if(c<=b && b<=a) return 3;
}

int main()
{
	int n;
	scanf("%d",&n);
	long long int a[n+10], idx=0;
	a[0]=1;
	long long int queue3[100000], queue5[100000], queue7[100000], head3=0, head5=0, head7=0, tail3=-1, tail5=-1, tail7=-1;
	tail3++, queue3[tail3]=3;
	tail5++, queue5[tail5]=5;
	tail7++, queue7[tail7]=7;

	while(idx<n)
	{
		long long int min=minimum(queue3[head3], queue5[head5], queue7[head7]);
		if(min==1)
		{
			idx++;
			a[idx]=queue3[head3];
			head3++;
			tail3++, tail5++, tail7++;
			queue3[tail3]=3*a[idx], queue5[tail5]=5*a[idx], queue7[tail7]=7*a[idx];
		}
		else if(min==2)
		{
			idx++;
			a[idx]=queue5[head5];
			head5++;
			tail5++, tail7++;
			queue5[tail5]=5*a[idx], queue7[tail7]=7*a[idx];
		}
		else if(min==3)
		{
			idx++;
			a[idx]=queue7[head7];
			head7++;
			tail7++;
			queue7[tail7]=7*a[idx];
		}	
	}
	printf("%lld",a[idx-1]);
	return 0;
}
