#include<cstdio>
#include<set>
using namespace std;

#define mp make_pair
#define MAX 100010
#define INF (int) 1e9
#define ll long long

int setUnionFind[MAX], countSets;
ll size[MAX];
set< pair<ll, int> > heap;

void init(int n)
{
	for(int i=0; i<n; ++i)
	{
		setUnionFind[i] = i;
		size[i] = 0;
		heap.insert(mp(0, i));
	}
	countSets = n;
}

int find(int i)
{
	return (setUnionFind[i] == i) ? i : setUnionFind[i] = find(setUnionFind[i]);
}

bool sameSet(int i, int j)
{
	return find(i) == find(j);
}

void unionSet(int i, int j, int w)
{
	heap.erase(mp(size[find(j)], find(j)));
	heap.erase(mp(size[find(i)], find(i)));
	if(!sameSet(i, j)) size[find(i)] += size[find(j)] + w;
	else size[find(i)] += w;
	heap.insert(mp(size[find(i)], find(i)));
	
	if(!sameSet(i, j)) countSets--;
	setUnionFind[find(j)] = setUnionFind[find(i)];
}

int main()
{
	int n, m, r, k, u, v, w;
	
	scanf("%d %d %d %d", &n, &m, &r, &k);
	init(n);
	for(int i=0; i<m; ++i)
	{
		scanf("%d %d %d", &u, &v, &w);
		--u; --v;
		unionSet(u, v, w);
	}
	
	if(countSets < k || (n == k && r > 0) || (countSets - r > k))
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	int count = 0;
	while((int)heap.size() > k && countSets > 1)
	{
		pair<ll, int> p1 = *heap.begin();
		heap.erase(heap.begin());
		pair<ll, int> p2 = *heap.begin();
		heap.erase(heap.begin());
		
		printf("%d %d\n", find(p1.second) + 1, find(p2.second) + 1);
	
		unionSet(p1.second, p2.second, min(1LL*INF, size[find(p1.second)] + size[find(p2.second)] + 1));
		heap.insert(mp(size[find(p1.second)], p1.second));

		++count;
		u = p1.second; v = p2.second;
	}
	if(count < r)
		for(; count<r; ++count)
			printf("%d %d\n", u+1, v+1);


	return 0;
}
