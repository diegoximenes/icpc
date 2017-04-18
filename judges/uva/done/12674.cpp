#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

#define pb push_back
#define mp make_pair
#define MAX 100010
#define INF (int) 1e9
#define PEAK 150000 

int n, v[MAX], tree[4*MAX], biggerRight[MAX], biggerLeft[MAX];
bool isProem[MAX];

void build(int node, int begin, int end)
{
	if(begin == end) tree[node] = v[begin];
	else
	{
		int mid = (begin + end)/2;
		build(2*node, begin, mid);
		build(2*node+1, mid+1, end);
		tree[node] = min(tree[2*node], tree[2*node+1]);
	}
}

int query(int node, int begin, int end, int left, int right)
{
	if(begin >= left && end <= right) return tree[node];
	else
	{
		int mid = (begin + end)/2, res = INF;

		if(mid >= left && begin <= right)
			res = min(res, query(2*node, begin, mid, left, right));
		if(end >= left && mid+1<=right)
			res = min(res, query(2*node+1, mid+1, end, left, right));
		return res;
	}
}

int query(int l, int r)
{
	return query(1, 1, n, l, r);
}

int main()
{
	while(scanf("%d", &n) == 1)
	{
		int maxheight = -1;
		for(int i=1; i<=n; ++i)
		{
			scanf("%d", &v[i]);
			maxheight = max(maxheight, v[i]);
		}
		build(1, 1, n);
		
		biggerRight[n-1] = -1;
		for(int i=n-2; i>=1; --i)
		{
			biggerRight[i] = i+1;
			while(biggerRight[i] != -1 && v[i] >= v[biggerRight[i]]) biggerRight[i] = biggerRight[biggerRight[i]];
			//printf("i= %d, r= %d\n", i, biggerRight[i]);
		}
		biggerLeft[2] = -1;
		for(int i=3; i<=n; ++i)
		{
			biggerLeft[i] = i-1;
			while(biggerLeft[i] != -1 && v[i] >= v[biggerLeft[i]]) biggerLeft[i] = biggerLeft[biggerLeft[i]];
			//printf("i= %d, l= %d\n", i, biggerLeft[i]);
		}
		
		bool first = 1;
		for(int i=2; i<n; ++i)
			if(v[i] > v[i-1] && v[i] > v[i+1])
			{
				int r = biggerRight[i], l = biggerLeft[i];
				
				//printf("i= %d, l= %d, r= %d\n", i, l, r);
					
				if(v[i] == maxheight) (first) ? printf("%d", i) , first = 0: printf(" %d", i);
				else
				{
					int distr = (r != -1) ? v[i] - query(i+1, r-1) : INF;
					int distl = (l != -1) ? v[i] - query(l+1, i-1) : INF;
					
					//printf("i= %d, distl= %d, distr= %d\n", i, distl, distr);

					if(distr >= PEAK && distl >= PEAK)
						(first) ? printf("%d", i) , first = 0 : printf(" %d", i);
				}
			}
		puts("");
	}

	return 0;
}
