#include<stdio.h>
#include<stdlib.h>

int cmpfunc(const void *a, const void *b)
{
	return (*(int *)a-*(int *)b);
}

int main()
{
	int n,i;
	scanf("%d",&n);
	int c[n];
	for(i=0; i<n; i++) scanf("%d",&c[i]);
	int m;
	scanf("%d",&m);
	int l[m];
	for(i=0; i<m; i++) scanf("%d",&l[i]);

	qsort(c, n, sizeof(int), cmpfunc);

	for(i=0; i<m; i++)
	{
		int index, start=0, end=n-1, mid;
		while(start<=end)
		{
			mid=(start+end)/2;

			if(c[mid]==l[i])
			{
				if(c[mid+1]>l[i]) { index=mid+1; break;}
				else if(c[mid+1]==l[i]) start=mid+1;
			}
			else if(c[mid]<l[i]) start=mid+1;
			else if(c[mid]>l[i])
			{
				if(c[mid-1]<=l[i]) { index=mid; break;}
				else if(c[mid-1]>l[i]) end=mid-1;
			}
		}
		if(c[n-1]<=l[i]) printf("0\n");
		else printf("%d\n",n-index);
		
	}

	return 0;
}









