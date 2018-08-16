#include<stdio.h>

void merge(long long l[][2], long long r[][2], long long a[][2], long long lsize, long long rsize)
{
	long long i=0,j=0,k=0;
	while(i<lsize && j<rsize)
	{
		if(l[i][0]<=r[j][0])
			a[k][0]=l[i][0], a[k][1]=l[i][1], i++, k++;
		else 
			a[k][0]=r[j][0], a[k][1]=r[j][1], j++, k++;
	}
	while(i<lsize) 
			a[k][0]=l[i][0], a[k][1]=l[i][1], i++, k++;
	while(j<rsize)
			a[k][0]=r[j][0], a[k][1]=r[j][1], j++, k++;
}

void mergesort(long long a[][2], long long asize)
{
	if(asize==1) return;
	long long lsize,rsize,i;
	lsize=asize/2;
	rsize=asize-lsize;
	long long l[lsize][2],r[rsize][2];
	for(i=0; i<lsize; i++){ l[i][0]=a[i][0]; l[i][1]=a[i][1];}
	for(i=0; i<rsize; i++){ r[i][0]=a[lsize+i][0]; r[i][1]=a[lsize+i][1];}

	mergesort(l, lsize);
	mergesort(r, rsize);
	merge(l, r, a, lsize, rsize);
}


int main()
{
	long long n,i;
	scanf("%lld",&n);
	long long se[n][2],p[n];
	for(i=0; i<n; i++) scanf("%lld%lld",&se[i][0],&se[i][1]);
	long long q,j,k,x,y;
	scanf("%lld",&q);
	mergesort(se, n);
	
	p[0]=se[0][1];
	for(i=1; i<n; i++) p[i]=p[i-1]+se[i][1];

	for(j=0; j<q; j++)
	{
		scanf("%lld%lld",&x,&y);
		long long start=0, end=n,mid,mx,my;	
		for(i=0; start<=end; i++)
		{
			mid=(start+end)/2;
			if(se[mid][0]<x) start=mid;
			else if(se[mid][0]>x)
			{
				if(mid>0 && se[mid-1][0]>=x) end=mid;
				else break;
			}
			else if(se[mid][0]==x)
			{
				for(k=mid-1; k>=0; k--)
				{
					if(se[0][0]==x){ mid=0; break;}
					if(se[k][0]==x) continue;
					else{ mid=k+1; break;}
				}
				break;
			}
		}
		mx=mid;
		start=0,end=n;
		for(i=0; start<=end; i++)
		{
			mid=(start+end)/2;
			if(se[mid][0]>y) end=mid;
			else if(se[mid][0]<y)
			{
				if(mid<n-1 && se[mid+1][0]<=y) start=mid;
				else break;
			}
			else if(se[mid][0]==y)
			{
				for(k=mid+1; k<n; k++)
				{
					if(se[n-1][0]==y){ mid=n-1; break;}
					if(se[k][0]==y) continue;
					else{ mid=k-1; break;}
				}
				break;
			}
		}
		my=mid;
		
		if(mx>0) printf("%lld\n",p[my]-p[mx-1]);
		else printf("%lld\n",p[my]);
//		printf("mx=%lld my=%lld\n",mx,my);
	}
	return 0;
}


















