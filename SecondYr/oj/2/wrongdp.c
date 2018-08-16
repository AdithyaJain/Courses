#include<stdio.h>
#include<stdlib.h>

int a[200000];
int mm[200000];
int mmg[200000];

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main()
{
  int n,m,i,j;
  scanf("%d%d",&n,&m);
  for(i=0; i<n; i++) scanf("%d",&a[i]);
  qsort(a, n, sizeof(int), cmpfunc);
  for(i=0; i<m; i++) mm[i] = 0, mmg[i]=0;
  for(i=0; i<n; i++) mm[a[i]] = 1, mmg[i]=i;
  int ptr = 0; //index of n[] which is lesser than i

  for(i=a[0] ; i<=m; i++)
  {
    if(i == a[ptr+1]) ptr++;
    for(j=ptr; j>=0; j--)
    {
      if(mm[i-a[j]] != 0 )
      {
      }
    }
  }

  printf("%d\n",mm[m]);
  return 0;
}
