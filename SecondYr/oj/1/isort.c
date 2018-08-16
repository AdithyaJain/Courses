#include <stdio.h>
#define SIZE 100000

void isort(int a[], int n)
{
	int i=0, j=0, k=0, temp;

	for(i=1; i<n; i++)
	{
		for(j=i-1; j>=0; j--) if(a[i] >= a[j]) break;
		temp = a[i];
		for(k=i; k>=j+2; k--) a[k] = a[k-1];
		a[j+1] = temp;
	}
}

int main()
{
	int a[SIZE];
	int i = 0;
	while(scanf("%d",&a[i]) != EOF) i++;
	int n = i;
	isort(a, n);
	for(i=0; i<n; i++) printf("%d ",a[i]);
	printf("\n");
	return 0;
}