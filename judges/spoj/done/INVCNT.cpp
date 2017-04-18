#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;

#define MAX 200000+10
#define ll long long

ll tree[MAX]; 
int a[MAX], b[MAX];

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

	if(i > j)
		return 1;
	else if(i < j)
		return -1;
	else 
		return 0;
}

int main()
{
	int t, n;

	scanf("%d", &t);
	while(t--)
	{
		memset(tree, 0, sizeof(tree));
		
		scanf("%d", &n);
		for(int i=0; i<n; ++i)
		{
			scanf("%d", &a[i]);
			b[i] = a[i];
		}

		sort(b, b+n);
		for(int i=0; i<n; ++i)
			a[i] = 1 + (int *)bsearch(a+i, b, n, sizeof(int), cmp)-b;

		ll invCount = 0;
		for(int i=n-1; i>=0; --i)
		{
			invCount += read(a[i]-1);
			update(a[i], 1);
		}
		printf("%lld\n", invCount);
	}

	return 0;
}
