#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int min(int a, int b);
int max(int a, int b);
void makeMinSeg(int a[], int tree[], int low, int high, int pos);
void makeMaxSeg(int a[], int tree[], int low, int high, int pos);
int rangeMin(int tree[], int qlow, int qhigh, int low, int high, int pos);
int rangeMax(int tree[], int qlow, int qhigh, int low, int high, int pos);
void updateMin(int tree[], int idx, int newVal, int low, int high, int pos);
void updateMax(int tree[], int idx, int newVal, int low, int high, int pos);

int main()
{
	int n,ni;
	scanf("%d",&n);
	int m,mi;
	scanf("%d",&m);
	int *a = (int*)malloc(n*sizeof(int));
	for(ni=0; ni<n; ni++) scanf("%d",&a[ni]);

	int *minTree = (int*)malloc((4*n)*sizeof(int));
	for(ni=0; ni<(4*n); ni++) minTree[ni] = INT_MAX;
	makeMinSeg(a, minTree, 0, n-1, 0);
	int *maxTree = (int*)malloc((4*n)*sizeof(int));
	for(ni=0; ni<(4*n); ni++) maxTree[ni] = -1;
	makeMinSeg(a, minTree, 0, n-1, 0);
	makeMaxSeg(a, maxTree, 0, n-1, 0);

	char c[2];
	for(mi=0; mi<m; mi++)
	{
		scanf("%s",c);
		if(c[0] == 'r')
		{
			int idx, x;
			scanf("%d%d",&idx,&x);
			idx--;
			a[idx] = x;
			updateMin(minTree, idx, x, 0, n-1, 0);
			updateMax(maxTree, idx, x, 0, n-1, 0);
		}
		else if(c[0] == 't')
		{
			int i,j;
			scanf("%d%d",&i,&j);
			i--, j--;
			int size = j-i+1;
			int diff = rangeMax(maxTree, i, j, 0, n-1, 0) - rangeMin(minTree, i, j, 0, n-1, 0);
			if(diff > size) printf("Yes\n");
			else printf("No\n");
			//			printf("%d %d\n",rangeMin(minTree, i, j, 0, n-1, 0), rangeMax(maxTree, i, j, 0, n-1, 0));	
		}
	}
	return 0;
}

int min(int a, int b)
{
	return (a>b)?b:a;
}
int max(int a, int b)
{
	return (a>b)?a:b;
}

void makeMinSeg(int a[], int tree[], int low, int high, int pos)
{
	if(low == high){ tree[pos] = a[low]; return;}

	int mid = (low + high)/2;
	makeMinSeg(a, tree, low, mid, 2*pos+1);
	makeMinSeg(a, tree, mid+1, high, 2*pos+2);
	tree[pos] = min(tree[2*pos+1], tree[2*pos+2]);
}
void makeMaxSeg(int a[], int tree[], int low, int high, int pos)
{
	if(low == high){ tree[pos] = a[low]; return;}

	int mid = (low + high)/2;
	makeMaxSeg(a, tree, low, mid, 2*pos+1);
	makeMaxSeg(a, tree, mid+1, high, 2*pos+2);
	tree[pos] = max(tree[2*pos+1], tree[2*pos+2]);
}

int rangeMin(int tree[], int qlow, int qhigh, int low, int high, int pos)
{
	if(qlow <= low && qhigh >= high) return tree[pos];
	else if(qlow > high || qhigh < low) return INT_MAX;
	else
	{
		int mid = (low+high)/2;
		return min(rangeMin(tree, qlow, qhigh, low, mid, 2*pos+1), rangeMin(tree, qlow, qhigh, mid+1, high, 2*pos+2));	
	}
}
int rangeMax(int tree[], int qlow, int qhigh, int low, int high, int pos)
{
	if(qlow <= low && qhigh >= high) return tree[pos];
	else if(qlow > high || qhigh < low) return -1;
	else
	{
		int mid = (low+high)/2;
		return max(rangeMax(tree, qlow, qhigh, low, mid, 2*pos+1), rangeMax(tree, qlow, qhigh, mid+1, high, 2*pos+2));
	}
}

void updateMin(int tree[], int idx, int newVal, int low, int high, int pos)
{
	if(low == high) tree[pos] = newVal;
	else
	{
		int mid = (low+high)/2;
		if(low <= idx && idx <= mid) updateMin(tree, idx, newVal, low, mid, 2*pos+1);
		else updateMin(tree, idx, newVal, mid+1, high, 2*pos+2);
		tree[pos] = min(tree[2*pos+1], tree[2*pos+2]);
	}

}
void updateMax(int tree[], int idx, int newVal, int low, int high, int pos)
{
	if(low == high) tree[pos] = newVal;
	else
	{
		int mid = (low+high)/2;
		if(low <= idx && idx <= mid) updateMax(tree, idx, newVal, low, mid, 2*pos+1);
		else updateMax(tree, idx, newVal, mid+1, high, 2*pos+2);
		tree[pos] = max(tree[2*pos+1], tree[2*pos+2]);
	}
}
