#include<stdio.h>

int partition(int a[], int l, int r)
{
	int i,j,temp;
	i=j=l+1;

	while(j<=r)
	{
		if(a[j]>=a[l]) j++;
		else 
		{
			temp=a[i], a[i]=a[j], a[j]=temp;
			i++, j++;
		}
	}
	temp=a[l], a[l]=a[i-1], a[i-1]=temp;
	return i-1;
}	

void quicksort(int a[], int l, int r)
{
	if(l>=r) return;
	int pivot=partition(a, l, r);
	
	quicksort(a, l, pivot-1);
	quicksort(a, pivot+1, r);

	return;
}

int main()
{
	int n,i;
	scanf("%d",&n);
	int a[n];
	for(i=0; i<n; i++) scanf("%d",&a[i]);
	quicksort(a, 0, n-1);
	for(i=0; i<n; i++) printf("%d",a[i]);
	return 0;
}

