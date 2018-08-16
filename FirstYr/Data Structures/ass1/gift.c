#include<stdio.h>

int binsearch(int a[], int l, int r, int x)
{
	int start=l, end=r, mid, index;
	while(start<=end)
	{
		mid=(start+end)/2;

		if(a[mid]==x)
		{
			if(mid==r) {index=mid+1; break;}
			else if(a[mid+1]>x) { index=mid+1; break;}
			else if(a[mid+1]==x) start=mid+1;
		}
		else if(a[mid]<x)
		{
			if(mid==r) {index=r+1; break;}
			else start=mid+1;
		}
		else if(a[mid]>x)
		{
			if(mid==0) {index=0; break;}
			if(a[mid-1]<=x) { index=mid; break;}
			else if(a[mid-1]>x) end=mid-1;
		}
	}
	return index;
}

int main()
{
	int a[100010]={0},idx=0,temp,i,bin;
	char c;
	
	for(;;)
	{
		scanf("%c",&c);
		if(c=='#') break;
		else if(c=='+')
		{
			scanf("%d",&temp);
			if(idx==0) a[0]=temp;
			else
			{
				bin=binsearch(a, 0, idx-1, temp);
				for(i=idx-1; i>=bin; i--)
					a[i+1]=a[i];
				a[bin]=temp;
			}
			idx++;
		}
		else if(c=='-')
		{
			if(idx==0) printf("-1\n");
			else {printf("%d\n",a[idx-1]); idx--;}
		}

	}

	return 0;
}






















