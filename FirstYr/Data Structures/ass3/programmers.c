#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define HZ 1000003
#define R 999983

long long stringNumber(char s[]);
void hashKey(long long n);
long long noOfEquals(long long n);
long long hash1(long long n);
long long hash2(long long n);

long long bin[62];
long long hash[HZ][2];

int main()
{
	long long t,ti;
	scanf("%lld",&t);
	for(ti=0; ti<t; ti++)
	{
		long long n, i;
		scanf("%lld",&n);
		memset(hash, 0, sizeof(hash));
		for(i=0; i<HZ; i++) hash[i][0]=0, hash[i][1]=0;
		char *s = (char*)malloc(1000010*sizeof(char));
		long long *strings = (long long*)malloc(n*sizeof(long long));

		for(i=0; i<n; i++)
		{
			scanf("%s",s);

			long long sn = stringNumber(s);
//			prlong longf("%lld\n",sn);

			hashKey(sn);
			strings[i] = sn;
		}
		//all strings r hashed till this polong long
		
//		for(i=0; i<n; i++) prlong longf("%lld\n",strings[i]);

		for(i=0; i<n; i++)
		{
			printf("%lld ",noOfEquals(strings[i]));
		}
		printf("\n");

		free(strings);
		free(s);

	}
	return 0;
}



void hashKey(long long n)
{
	long long h1 = hash1(n), h2 = hash2(n), iter, idx;

	for(iter=0; ; iter++)
	{
		idx = (h1 + iter*h2)%HZ;
		if(hash[idx][0] == 0){ hash[idx][0] = n; hash[idx][1]++; break;}
		else if(hash[idx][0] == n){ hash[idx][1]++; break;}
	}
//	prlong longf("hash[%lld] = %lld\n", idx, hash[idx]);
}

long long noOfEquals(long long n)
{
	long long h1 = hash1(n), h2 = hash2(n), iter, idx;
	for(iter=0; ; iter++)
	{
		idx = (h1 + iter*h2)%HZ;
		if(hash[idx][0] == n) return hash[idx][1];
	}
}


long long hash1(long long n)
{
	return n % HZ;
}
long long hash2(long long n)
{
	return R - (n % R);
}
long long stringNumber(char s[])
{
	long long n = strlen(s), i;

	for(i=0; i<62; i++) bin[i]=0;

	long long* a = (long long*)malloc(n*sizeof(long long));

	for(i=0; i<n; i++) a[i] = s[i];

	for(i=0; i<n; i++)
	{
		if(a[i] >= 48 && a[i] <= 57) //0-9
		{
			bin[a[i]-48] = 1;
		}
		else if(a[i] >= 65 && a[i] <= 90) //A-Z
		{
			bin[a[i]-55] = 1;
		}
		else if(a[i] >= 97 && a[i] <= 122) //a-z
		{
			bin[a[i]-61] = 1;
		}
	}

	long long ans = 0, pow=1;
	for(i=0; i<62; i++)
	{
		ans += bin[i] * pow;
		pow = pow*2;
	}

	free(a);
	return ans;
}
