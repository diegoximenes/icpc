#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;

#define MAX 100000+10
#define ll long long

ll tree[MAX]; 
int a[MAX];

ll read(int idx)
{
	ll sum = 0;
	while(idx > 0)
	{
		sum += tree[idx];
		idx -= (idx & -idx);
	}
	return sum;
}

void update(int idx, ll val)
{
	while(idx < MAX)
	{
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

int cmp(const void *n1, const void *n2)
{
	int i = *((int *)n1), j = *((int *)n2);

	if(i > j) return 1;
	else if(i < j) return -1;
	else return 0;
}

int main()
{
	int n;

	while(scanf("%d", &n) && n)
	{
		memset(tree, 0, sizeof(tree));
		
		for(int i=0; i<n; ++i)
			scanf("%d", &a[i]);

		ll invCount = 0;
		for(int i=n-1; i>=0; --i)
		{
			invCount += read(a[i]-1);
			update(a[i], 1);
		}

		if(invCount%2 != 0) puts("Marcelo");
		else puts("Carlos");
	}

	return 0;
}
