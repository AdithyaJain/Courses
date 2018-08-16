#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int c1;
	int c2;
	int weight;
}node;

int cmpfunc(const void * a, const void * b);
int find(int x);
void Union(int root1, int root2);
node edge[500010];
int u[100010];

int main()
{
	int t, n, m, i, loop, count, root1, root2;
	long long sum;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(i=0; i<m; i++)
		{
			scanf("%d%d%d",&edge[i].c1, &edge[i].c2, &edge[i].weight);
		}
		for(i=0; i<n; i++) u[i] = -1;
		qsort(edge, m, sizeof(node), cmpfunc);
//		for(i=0; i<m; i++) printf("c1 %d c2 %d w %d\n",edge[i].c1, edge[i].c2, edge[i].weight);
//TILL HERE, SORTED EDGES LIST PREPARED
		sum = 0;
		loop = 0, count = 0, i=0;
		for(i=0; i<m; i++)
		{
			if(count == n) break;
			root1 = find(edge[i].c1), root2 = find(edge[i].c2);
			if(root1 != root2)
			{
				count++;
				Union(root1, root2);
				sum += edge[i].weight;
			}
			else
			{
				if(loop == 0)
				{
					sum += edge[i].weight;
					loop++;
				}
			}
		}

		printf("%lld\n",sum);
	}
	return 0;
}

int cmpfunc(const void * a, const void * b)
{
	return ((node*)a)->weight - ((node*)b)->weight;
}

int find(int x)
{
	if(u[x] < 0) return x;
	else return find(u[x]);
}

void Union(int root1, int root2)
{
	if((-u[root1]) == (-u[root2]))
	{
		u[root2] = root1;
		u[root1]--;
	}	
	else if((-u[root1]) < (-u[root2])) u[root1] = root2;
	else u[root2] = root1;
}
