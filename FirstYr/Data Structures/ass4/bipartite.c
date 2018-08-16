#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int n;
	struct node *next;
}node;

node* adjList[100010];
int color[100010];
int queue[100010];
int bfs(int vertex);

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);

	int i;
	for(i=0; i<=n; i++) {adjList[i] = NULL; color[i] = -1;}
	for(i=0; i<m; i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(adjList[x] == NULL)
		{
			node* temp = (node*)malloc(sizeof(node));
			temp->n = y;
			temp->next = NULL;
			adjList[x] = temp;
		}
		else
		{
			node* temp = (node*)malloc(sizeof(node));
			temp->n = y, temp->next = adjList[x];
			adjList[x] = temp;
		}
		if(adjList[y] == NULL)
		{
			node* temp = (node*)malloc(sizeof(node));
			temp->n = x;
			temp->next = NULL;
			adjList[y] = temp;
		}
		else
		{
			node* temp = (node*)malloc(sizeof(node));
			temp->n = x, temp->next = adjList[y];
			adjList[y] = temp;
		}

	}
/*	for(i=1; i<=n; i++)
	{
		node* temp;
		for(temp=adjList[i]; temp!=NULL; temp = temp->next) printf("%d ",temp->n);
		printf("\n");
	}*/

	int flag = 1;
	for(i=1; i<=n; i++) if(color[i] == -1) if(bfs(i) == 0){ flag=0; break;}
	if(flag) printf("Yes\n");
	else printf("No\n");
	
	return 0;
}

int bfs(int vertex)
{
	int top = 0, tail = 0;
	queue[0] = vertex;
	color[vertex]=1;
	while(top <= tail)//queue is not empty
	{
		node* temp = adjList[queue[top]];
		for(; temp!=NULL; temp = temp->next)
		{
			if((temp->n) == queue[top]) continue;
			if(color[temp->n] == -1)
			{
				if(color[queue[top]] == 0) color[temp->n] = 1;
				else if(color[queue[top]] == 1) color[temp->n] = 0;
				tail++;
				queue[tail] = temp->n;
			}
			else
			{
				if(color[queue[top]] == color[temp->n]) return 0;
			}
		}
		top++;
	}
	return 1;
}
