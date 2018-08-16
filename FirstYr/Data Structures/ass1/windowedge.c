#include<stdio.h>

int partition(int a[], int l, int r)
{
	int i,j,temp;
	i=j=l+1;

	while(j<=r)
	{
		if(a[j]<=a[l]) j++;
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
	int n,k,i,j;
	scanf("%d%d",&n,&k);
	char s[n],a[n];
	scanf("%s",s);
	for(i=0; i<n; i++) a[i]=s[i]-'0';

	for(i=0; i<k; i++)
	{
		int temp[(n/k)+1];
		temp[n/k]=-1;
		for(j=0; j<=(n/k) && ((i+(j*k))<n); j++) temp[j]=a[i+(j*k)];

		quicksort(temp, 0, n/k);
		
		for(j=0; j<=(n/k) && ((i+(j*k))<n); j++) a[i+(j*k)]=temp[j];
	}

	for(i=0; i<n; i++) printf("%d",a[i]);
	printf("\n");
	return 0;
}
