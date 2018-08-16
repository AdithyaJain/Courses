#include<stdio.h>
#include<string.h>

int main()
{
	long long t,ti;
	scanf("%lld",&t);
	for(ti=0; ti<t; ti++)
	{
		char ac[110];
		scanf("%s",ac);
		int a[110]={0},i,nonzero,prod,carry=0;
		for(i=0; i<strlen(ac); i++) a[110-strlen(ac)+i]=ac[i]-'0';

		for(i=109; i>=0; i--)
			if(a[i]!=0){ nonzero=i; break;}

		a[nonzero]--;
		for(i=nonzero+1; i<110; i++) a[i]=9;


		for(i=109; i>=0; i--)
		{
			prod=(a[i]*2)+carry;
			carry=prod/10;
			a[i]=prod%10;
		}




		for(i=0; i<110; i++) 
			if(a[i]!=0)
			{
				nonzero=i;
				break;
			}

		int flag=1;
		for(i=0; i<110; i++) if(a[i]!=0) {flag=0; break;}	
		if(flag==1) printf("1");
		else for(i=nonzero; i<110; i++) printf("%d",a[i]);
		printf("\n");
	}
	return 0;
}
