#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int size=10;
int* a;

void hash(int key);
void rehash();
int hashFunc(int key, int iter);
int sec(int iter);

int main()
{
	a = (int *)malloc(size*sizeof(int));
	int temp, count=0, i;
	for(i=0; i<size; i++) a[i]=-1;
	
	for(;;)
	{
		scanf("%d",&temp);
		if(temp==-1) break;
		else count++;
		
		if(count>size/2) //rehash
		{
			rehash();
		}
		
		hash(temp);
		
		for(i=0; i<size; i++) printf("%d ",a[i]);
		printf("\n");
	}

	return 0;
}


void hash(int key)
{
	int iter=0;
	for(iter=0;; iter++)
	{
		int h=hashFunc(key, iter);
		if(a[h]==-1){ a[h]=key; break;}
		else continue;
	}
}

int sec(int iter)
{
	return iter;
}

int hashFunc(int key, int iter)
{
	return (key%size+sec(iter));
}

void rehash()
{
	int i;
	a = realloc(a, (2*size)*sizeof(int));
	for(i=size; i<2*size; i++) a[i]=-1;
	size=size*2;
	
	//hash the one already present

}
