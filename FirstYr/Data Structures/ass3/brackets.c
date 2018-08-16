#include<stdio.h>
#include<stdlib.h>

int stack[100010];
void push(int a);
void pop();
int isEmpty();
int top = -1;
void emptyStack();

int main()
{
	int t, ti;
	scanf("%d",&t);
	for(ti=0; ti<t; ti++)
	{
		int n, k, i;
		scanf("%d%d",&n,&k);
		int* a = (int*)malloc((n+1)*sizeof(int));
		for(i=0; i<n; i++) scanf("%d",&a[i+1]);
		emptyStack();
		int max = 0;
		push(0);

		for(i=1; i<=n; i++)
		{
			if(a[i] > 0) push(i);
			else
			{
				int idx = stack[top];
				pop();
				if((a[idx] == -a[i]) && (isEmpty() == 0)) max = ((i-stack[top]) > max) ? (i-stack[top]) : max;			
				else push(i);
			}
		}
		printf("%d\n",max);
		free(a);		
	}
	return 0;
}

void push(int a)
{
	top++;
	stack[top] = a;
}
void pop()
{
	if(top > -1) top--;
}
int isEmpty()
{
	if(top == -1) return 1;
	else return 0;
}
void emptyStack()
{
	while(top > -1) pop();
}
