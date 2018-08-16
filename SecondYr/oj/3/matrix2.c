#include <stdio.h>
#include <limits.h>
long long matrix(long long p[], long long n)
{
    long long m[n][n];
    long long i, j, k, L, q;
    for (i=1; i<n; i++)
        m[i][i] = 0;
    for (L=2; L<n; L++)
    {
        for (i=1; i<n-L+1; i++)
        {
            j = i+L-1;
            m[i][j] = INT_MAX;
            for (k=i; k<=j-1; k++)
            {
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }
    return m[1][n-1];
}
int main()
{
  long long a[600];
  long long n,i;
  scanf("%lld",&n);
  for(i=0; i<=n; i++) scanf("%lld",&a[i]);


  printf("%lld\n",matrix(a,n+1));
  return 0;
}
