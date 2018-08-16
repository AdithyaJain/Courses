#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int main()
{
	int t, ti;
	scanf("%d",&t);
	for(ti=0; ti<t; ti++)
	{
		int n,i;
		scanf("%d",&n);
		int* a = (int*)malloc(n*sizeof(int));
		for(i=0; i<n; i++) scanf("%d",&a[i]);

		int k;
		scanf("%d",&k);
		int* seq = (int*)malloc(k*sizeof(int));
		for(i=0; i<k; i++) scanf("%d",&seq[i]);
		//scanned array and query


		int llimit = -INT_MAX, rlimit = INT_MAX, start = seq[0], end = seq[k-1];
		
		int* pathstart = (int*)malloc(n*sizeof(int));
		int* pathend = (int*)malloc(n*sizeof(int));

		int sidx = 0, eidx = 0;

		for(i=0; i<n; i++)
		{
			if(a[i] == start){ pathstart[sidx] = start; break;}
			else if(a[i] < start)
			{
				if(a[i] > llimit)
				{
					llimit = a[i];
					pathstart[sidx] = a[i];
					sidx++;
				}
			}
			else if(a[i] > start)
			{
				if(a[i] < rlimit)
				{
					rlimit = a[i];
					pathstart[sidx] = a[i];
					sidx++;
				}
			}	
		}

		eidx = 0, llimit = -INT_MAX, rlimit = INT_MAX;
		for(i=0; i<n; i++)
		{
			if(a[i] == end){ pathend[eidx] = end; break;}
			else if(a[i] < end)
			{
				if(a[i] > llimit)
				{
					llimit = a[i];
					pathend[eidx] = a[i];
					eidx++;
				}
			}
			else if(a[i] > end)
			{
				if(a[i] < rlimit)
				{
					rlimit = a[i];
					pathend[eidx] = a[i];
					eidx++;
				}
			}
		}
/*		for(i=0; i<=sidx; i++) printf("%d ",pathstart[i]);
		printf("\n");
		for(i=0; i<=eidx; i++) printf("%d ",pathend[i]);
		printf("\n");
*/
		int commonidx = 0;
		for(commonidx=0; commonidx <= sidx && commonidx <= eidx ; commonidx++)
		{
			if(pathstart[commonidx] != pathend[commonidx]) break;
		}
		commonidx--; //last common numbers' index

//printf("sidx=%d eidx=%d commonidx=%d",sidx,eidx,commonidx);

		int flag = 1, seqidx = 0;
		for(i = sidx; i >= commonidx; i--)
		{
			if(pathstart[i] == seq[seqidx]) seqidx++;
			else {flag = 0; break;}
		}
		for(i = commonidx+1; i <= eidx; i++)
		{
			if(pathend[i] == seq[seqidx]) seqidx++;
			else {flag = 0; break;}
		}

		if(flag == 1) printf("Yes\n");
		else printf("No\n");
		
		free(a);
		free(seq);
		free(pathstart);
		free(pathend);
	}
	return 0;
}
