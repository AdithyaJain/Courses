#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
typedef struct node{
	int c1;
	int c2;
	int weight;
}node;
int coord[1510][2];

int cmpfunc(const void * a, const void * b);
int find(int u[], int x);
void Union(int u[], int root1, int root2);

int main()
{
	int t, ti;
	scanf("%d",&t);
	for(ti=0; ti<t; ti++)
	{
		int n,i,j;
		scanf("%d",&n);
		node* edge = (node*)malloc(n*n*sizeof(node));
		int idx = 0, minFromGate = INT_MAX;
		for(i=0; i<n; i++)
		{
			scanf("%d%d",&coord[i][0], &coord[i][1]);
			if((coord[i][0] + coord[i][1]) < minFromGate) minFromGate = coord[i][0] + coord[i][1];
			for(j=0; j<i; j++)
			{
				edge[idx].c1 = i, edge[idx].c2 = j;
				edge[idx].weight = abs(coord[i][0] - coord[j][0]) + abs(coord[i][1] - coord[j][1]);
				idx++;
			}
		}
		qsort(edge, idx, sizeof(node), cmpfunc);
//		for(i=0; i<idx; i++) printf("c1 %d c2 %d w %d\n",edge[i].c1, edge[i].c2, edge[i].weight);
//TILL HERE, SORTED EDGES LIST PREPARED
		long long sum = 0;
		int* u = (int*)malloc(n*sizeof(int));
		for(i=0; i<n; i++) u[i] = -1;
		
		for(i=0; i<idx; i++)
		{
			int root1 = find(u, edge[i].c1), root2 = find(u, edge[i].c2);
			if(root1 != root2)
			{
				Union(u, root1, root2);
				sum += edge[i].weight;
			}
		}

		printf("%lld\n",sum + minFromGate);

		free(u);
		free(edge);
	}
	return 0;
}

int cmpfunc(const void * a, const void * b)
{
	return ((node*)a)->weight - ((node*)b)->weight;
}

int find(int u[], int x)
{
	while(u[x] >= 0)
	{
		x = u[x];
	}
	return x;
}

void Union(int u[], int root1, int root2)
{
	if(abs(u[root1]) == abs(u[root2]))
	{
		u[root2] = root1;
		u[root1]--;
	}	
	else if(abs(u[root1]) < abs(u[root2])) u[root1] = root2;
	else u[root2] = root1;
}
