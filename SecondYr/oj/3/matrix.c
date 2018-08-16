#include<stdio.h>
#include<limits.h>

long long a[600];
long long m[600][600];

long long matrix(long long i, long long j)
{
  if (i == j) return 0;
  long long k, temp;
  for(k=i; k<j; k++)
  {
    if(m[i][k] == INT_MAX) m[i][k] = matrix(i,k);
    if(m[k+1][j] == INT_MAX) m[k+1][j] = matrix(k+1,j);
    temp = m[i][k] + m[k+1][j] + a[i-1]*a[k]*a[j];

    if(m[i][j] > temp) m[i][j] = temp;
  }
  return m[i][j];
}

int main()
{
  long long n,i,j;
  scanf("%lld",&n);
  for(i=0; i<=n; i++) scanf("%lld",&a[i]);

  for(i=1;i<=n;i++) for(j=1;j<=n;j++) m[i][j]=INT_MAX;
  for(i=1; i<=n; i++) m[i][i] = 0;
  matrix(1,n);
  printf("%lld\n",m[1][n]);

  //printf("%lld\n",matrix(1,n));
  return 0;
}
