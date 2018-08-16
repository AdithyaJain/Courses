#include<stdio.h>

void merge(int a[], int b[], int c[], int l, int r)
{
	int i=0,j=0,k=0;
	
	while(i<l && j<r)
	{
		if(b[i]<c[j]) a[k]=b[i], k++, i++;
		if(c[j]<=b[i]) a[k]=c[j], k++, j++;
	}

	while(i<l) a[k]=b[i], k++, i++;
	while(j<r) a[k]=c[j], k++, j++;
	return;
}

void mergesort(int a[], int n)
{
	if(n==1) return;
	int i,l,r;
	l=n/2;
	r=n-l;
	int b[l],c[r];
	
	for(i=0; i<l; i++) b[i]=a[i];
	for(i=0; i<r; i++) c[i]=a[i+l];

	mergesort(b, l);
	mergesort(c, r);
	merge(a, b, c, l, r);
	return;
}

int main()
{
	int n,i;
	scanf("%d",&n);
	int a[n];
	for(i=0; i<n; i++) scanf("%d",&a[i]);

	mergesort(a, n);
	for(i=0; i<n; i++) printf("%d",a[i]);

	return 0;
}
