#include<stdio.h>

void heapify(int a[], int n, int i);
void build(int a[], int n);
void heapsort(int a[], int n);

int main()
{
	int n,i;
	scanf("%d",&n);
	int a[n+1];
	a[0]=0;
	for(i=1; i<=n; i++) scanf("%d",&a[i]);
	heapsort(a,n);
	for(i=1; i<=n; i++) printf("%d",a[i]);
	return 0;
}

void heapify(int a[], int n, int i)
{
	int l=2*i ,r=l+1, max, temp;

	if(l<=n)
	{
		if(a[l]>a[i]) max=l;
		else max=i;
		if(r<=n && a[r]>a[max]) max=r; 
	}
	else max=i;

	if(max!=i)
	{
		temp=a[i], a[i]=a[max], a[max]=temp;
		heapify(a, n, max);
	}
	return;
}

void build(int a[], int n)
{
	int i;
	for(i=n/2; i>=1; i--)
		heapify(a, n, i);
	return;
}

void heapsort(int a[], int n)
{
	build(a,n);
	int i,temp;
	for(i=n; i>=1; i--)
	{
		temp=a[i], a[i]=a[1], a[1]=temp;
		n--;
		heapify(a, n, 1);
	}
	return;
}
