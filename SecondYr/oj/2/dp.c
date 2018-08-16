#include<stdio.h>
#include<stdlib.h>

int a[200000];
int mm[310][150010];

int sum(int i, int j)
{
  if (i == 0) return 0;
  //if(j == 0) return 1;
  if (mm[i-1][j] == -1) mm[i-1][j] = sum(i-1, j);
  if(j-a[i] >= 0)
  {
     if (mm[i][j-a[i]] == -1) mm[i][j-a[i]] = sum(i, j-a[i]);
     mm[i][j] = (mm[i-1][j] + mm[i][j-a[i]]) % 1000000007;
   }
   else
   {
     mm[i][j] = (mm[i-1][j]) % 1000000007;
   }
  //mm[i][j] = (mm[i-1][j] > mm[i][j-a[i]] + 1)?mm[i-1][j]:mm[i][j-a[i]] + 1;

  return mm[i][j];
}

int main()
{
  int n,m,i,j;
  scanf("%d%d",&n,&m);
  for(i=1; i<=n; i++) scanf("%d",&a[i]);

  for(i=0; i<=n; i++)
    for(j=0; j<=m; j++) mm[i][j] = -1;

  for(i=1; i<=n; i++) mm[i][0] = 1;

  printf("%d\n",sum(n, m));

  return 0;
}
