#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAX 100005

int n, k, q, dp[MAX], dic[MAX];
pair<int, int> v[MAX];

int main()
{
	scanf("%d %d %d", &n, &k, &q);
	for(int i=0; i<n; ++i)
	{
		scanf("%d", &v[i].first); 
		v[i].second = i;
	}

	sort(v, v+n);

	for(int i=0; i<n; ++i) dic[v[i].second] = i;

	dp[n-1] = 0;
	for(int i=n-2; i>=0; --i)
	{
		if(v[i+1].first - v[i].first <= k) dp[i] = 1 + dp[i+1];
		else dp[i] = 0;
	}
	
	while(q--)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		
		--x; --y;
		x = dic[x], y = dic[y];
		if(x > y) swap(x, y);

		if(dp[x] + x >= y) puts("Yes");
		else puts("No");
	}

	return 0;
}
