#include <stdio.h>

long long cut(long long* p, long long n, long long N);
long long m[4000];
long long p[4000];

int main()
{
  long long N;
  scanf("%lld",&N);

  long long i;
  for(i=1; i<=N-1; i++)
  {
    scanf("%lld",&p[i]);
  }

  for(i=1; i<=N; i++) m[i] = -1;

  printf("%lld\n",cut(p,N,N));
  return 0;
}

long long cut(long long* p, long long n, long long N)
{
  if (n==0) return 0;
  long long q = -1, i=0;

  for(i=1; i<=n; i++)
  {
    if(i != N)
    {
      if(m[n-i] == -1) m[n-i] = cut(p,n-i,N);
      q = (q > m[n-i]+p[i]) ? q : m[n-i]+p[i];
    }
  }
  return q;
}
