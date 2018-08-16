#include<stdio.h>
#include<stdlib.h>

int sum(int h[], int n);
int min(int sum[]);

int main()
{
	int t,ti;
	scanf("%d",&t);
	for(ti=0; ti<t; ti++)
	{
		int n[3],i;
		scanf("%d",&n[0]);
		int h0[n[0]];
		for(i=0; i<n[0]; i++) scanf("%d",&h0[i]);
		scanf("%d",&n[1]);
		int h1[n[1]];
		for(i=0; i<n[1]; i++) scanf("%d",&h1[i]);
		scanf("%d",&n[2]);
		int h2[n[2]];
		for(i=0; i<n[2]; i++) scanf("%d",&h2[i]);

		int s[3];
		s[0] = sum(h0, n[0]); 
		s[1] = sum(h1, n[1]); 
		s[2] = sum(h2, n[2]); 
		for(;;)
		{

			if(s[0]==s[1] && s[1]==s[2]){ printf("%d\n",s[0]); break;}
			int m = min(s);
			if(m!=0 && s[m]<s[0]) {s[0]=s[0]-h0[n[0]-1]; n[0]--;}
			if(m!=1 && s[m]<s[1]) {s[1]=s[1]-h1[n[1]-1]; n[1]--;}
			if(m!=2 && s[m]<s[2]) {s[2]=s[2]-h2[n[2]-1]; n[2]--;}
		}
	}
	return 0;
}
sum(int h[], int n)
{
	int i, sum=0;
	for(i=0; i<n; i++)
		sum=sum+h[i];
	return sum;
}
int min(int sum[])
{
	int temp[3],i;
	for(i=0; i<3; i++) temp[i]=sum[i];
	qsort(temp, 3, sizeof(int), cmpfunc);
	if(sum[0]==temp[0]) return 0;
	if(sum[1]==temp[0]) return 1;
	if(sum[2]==temp[0]) return 2;
}
