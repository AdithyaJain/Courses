#include<stdio.h>

int binsearch(int a[], int l, int r, int x);
int partition(int a[][2], int l, int r);
void quicksort(int a[][2], int l, int r);

int main()
{
	int n,i,j;
	scanf("%d",&n);
	int s[n+1][2];
	s[0][0]=0, s[0][1]=0;
	for(i=1; i<=n; i++) { scanf("%d",&s[i][0]); s[i][1]=i;}

	quicksort(s, 0, n);
	//	for(i=1; i<=n; i++) printf("%d %d\n",s[i][0], s[i][1]);
	int a[n+1],bin;
	a[0]=0;
	for(i=1; i<=n; i++)
	{
		if(i==1) a[i]=s[i][1];
		else
		{
			bin=binsearch(a, 0, i-1, s[i][1]);
			for(j=i-1; j>=bin; j--) a[j+1]=a[j];
			a[bin]=s[i][1];
	//		a[i]=s[i][1];
		}
		for(j=1; j<i; j++) printf("%d ",a[j]);
		printf("%d\n",a[i]);
	}	

	return 0;
}

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

int partition(int a[][2], int l, int r)
{
	int i,j,temp;
	i=j=l+1;

	while(j<=r)
	{
		if(a[j][0]>=a[l][0]) j++;
		else
		{
			temp=a[i][0], a[i][0]=a[j][0], a[j][0]=temp;
			temp=a[i][1], a[i][1]=a[j][1], a[j][1]=temp;
			i++, j++;
		}
	}
	temp=a[l][0], a[l][0]=a[i-1][0], a[i-1][0]=temp;
	temp=a[l][1], a[l][1]=a[i-1][1], a[i-1][1]=temp;
	return i-1;
}

void quicksort(int a[][2], int l, int r)
{
	if(l>=r) return;
	int pivot=partition(a, l, r);

	quicksort(a, l, pivot-1);
	quicksort(a, pivot+1, r);

	return;
}
