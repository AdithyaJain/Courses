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
	//Just make ur own main()
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