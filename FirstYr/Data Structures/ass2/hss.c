#include<stdio.h>
long long int stack[200020]={0}, temp[200020]={0}, nec[200020][2];
void merge(long long l[][3], long long r[][3], long long a[][3], long long lsize, long long rsize);
void mergesort(long long a[][3], long long asize);

int main()
{
	int n,i;
	scanf("%d",&n);
	long long canvas[100010][3], list[200020][3];
	for(i=0; i<n; i++) 
	{
		scanf("%lld%lld%lld",&canvas[i][2], &canvas[i][0], &canvas[i][1]);
		list[2*i][0]=0, list[2*i][1]=canvas[i][0], list[2*i][2]=canvas[i][2];
		list[2*i+1][0]=1, list[2*i+1][1]=canvas[i][1], list[2*i+1][2]=canvas[i][2];
	}
	mergesort(list, 2*n);
//	for(i=0; i<2*n; i++) printf("%lld %lld %lld\n",list[i][0], list[i][1], list[i][2]);

	int stacki=0, tempi=-1, neci=-1, max=0;
	for(i=0; i<(2*n); i++)
	{
		if(list[i][0]==0) //start
		{
			if(list[i][2] > max) 
			{
				max=list[i][2];
				stacki++;
				stack[stacki]=list[i][2];
				neci++;
				nec[neci][0]=list[i][1], nec[neci][1]=list[i][2];
			}
		}
		else if(list[i][0]==1) //end
		{
			if(stack[stacki]==list[i][2]) max=stack[stacki-1], neci++, nec[neci][0]=list[i][1], nec[neci][1]=stack[stacki-1];
			while(stack[stacki]!=list[i][2] && stacki>0)
			{
				tempi++;
				temp[tempi]=stack[stacki];
				stacki--;
			}
			while(tempi!=-1)
			{
				stack[stacki]=temp[tempi];
				stacki++, tempi--;
			}
			stacki--;
		}
	}
//	for(i=0; i<=neci; i++) printf("%lld %lld\n",nec[i][0], nec[i][1]);
	long long area=0;
	for(i=0; i<neci; i++)
	{
		area = (area + (nec[i+1][0]-nec[i][0])*nec[i][1])%(1000000009);
	}

	printf("%lld\n",area);
	return 0;
}

void merge(long long l[][3], long long r[][3], long long a[][3], long long lsize, long long rsize)
{
	long long i=0,j=0,k=0;
	while(i<lsize && j<rsize)
	{
		if(l[i][1]<=r[j][1])
			a[k][0]=l[i][0], a[k][1]=l[i][1], a[k][2]=l[i][2], i++, k++;
		else
			a[k][0]=r[j][0], a[k][1]=r[j][1], a[k][2]=r[j][2], j++, k++;
	}
	while(i<lsize)
		a[k][0]=l[i][0], a[k][1]=l[i][1], a[k][2]=l[i][2], i++, k++;
	while(j<rsize)
		a[k][0]=r[j][0], a[k][1]=r[j][1], a[k][2]=r[j][2], j++, k++;
}

void mergesort(long long a[][3], long long asize)
{
	if(asize==1) return;
	long long lsize,rsize,i;
	lsize=asize/2;
	rsize=asize-lsize;
	long long l[lsize][3],r[rsize][3];
	for(i=0; i<lsize; i++){ l[i][0]=a[i][0]; l[i][1]=a[i][1]; l[i][2]=a[i][2];}
	for(i=0; i<rsize; i++){ r[i][0]=a[lsize+i][0]; r[i][1]=a[lsize+i][1]; r[i][2]=a[lsize+i][2];}

	mergesort(l, lsize);
	mergesort(r, rsize);
	merge(l, r, a, lsize, rsize);
}
