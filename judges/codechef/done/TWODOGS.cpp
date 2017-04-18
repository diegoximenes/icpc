#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define INF 1e9
#define MAX 1000010
#define MAX2 500010

int right[MAX], left[MAX], n, k, v[MAX2], cnt[MAX];

int main()
{
	scanf("%d %d", &n, &k);
	for(int i=0; i<n; ++i)
	{
		scanf("%d", &v[i]);
		right[v[i]] = i;
		if(cnt[v[i]] == 0) left[v[i]] = i;
		cnt[v[i]]++;
	}
	
	int sol = INF, upper = k/2;
	for(int i=1; i<upper; ++i)
	{
		if(cnt[i] == 0 || cnt[k-i] == 0 || i == k-i) continue;

		int sol1 = (left[i] != right[k-i]) ? max(1 + left[i], n - right[k-i]) : INF;
		int sol2 = (left[k-i] != right[i]) ? max(1 + left[k-i], n - right[i]) : INF;
		int sol3 = (left[i] != left[k-i]) ? max(1 + left[k-i], 1 + left[i]) : INF;
		int sol4 = (right[i] != right[k-i]) ? max(n - right[k-i], n - right[i]) : INF;
		
		sol = min(sol, min(min(sol1, sol2), min(sol3, sol4)));
	}
	printf("%d\n", (sol == INF) ? -1 : sol);

	return 0;
}
