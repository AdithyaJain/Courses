#include<stdio.h>
int main()
{
	int t,ti;
	scanf("%d",&t);
	for(ti=0; ti<t; ti++)
	{
		int n,i,j;
		scanf("%d",&n);
		int a[9],gln=0,min;
		for(i=0; i<9; i++) scanf("%d",&a[i]);
		min=a[0];
		for(i=0; i<9; i++) if(a[i]<min) min=a[i];
		for(i=8; i>=0; i--) if(a[i]==min) 
		{
			gln=i+1;
			break;
		}

		//		printf("min=%d\tgln=%d\n",min,gln);

		if(n>=min)
		{
			int numofdig=n/min, rem=n%min, count=0, diff[9];
			for(i=0; i<9; i++) diff[i]=a[i]-min;
			//			for(i=0; i<9; i++) printf("%d\n",diff[i]);

			for(i=8; i>=gln; i--)
			{
				if(rem>=diff[i])
				{
					int num_of_possibilities=rem/diff[i];
					for(j=0; j<num_of_possibilities && j<numofdig; j++)
					{
						printf("%d",i+1);
						count++;			
					}
					rem=rem%diff[i];

				}
			}
			for(i=0; i<(numofdig-count); i++) printf("%d",gln);
			printf("\n");
		}
		else printf("-1\n");
	}
	return 0;
}
