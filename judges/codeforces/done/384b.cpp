#include<cstdio>
#include<cctype>
#include<cstring>
#include<cmath>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<bitset>
#include<map>
#include<queue>
#include<stack>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define INF 1e9
#define NMAX 1005
#define MMAX 105

int n, m, k, cnt[MMAX], ord, x;
vector<int> v[NMAX], v2[NMAX];

bool cmp(int a, int b)
{
	if(a > b) return 1;
	return 0;
}

int main()
{
	
	scanf("%d %d %d", &n, &m, &ord);
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			scanf("%d", &x), v[i].pb(x), v2[i].pb(x);

	for(int i=0; i<n; ++i)
	{
		if(!ord) sort(v2[i].begin(), v2[i].end());
		else sort(v2[i].begin(), v2[i].end(), cmp);
	}

	vector< pair<int, int> > vec;
	int i = 0;
	while(i<m)
	{
		memset(cnt, 0, sizeof(cnt));
		for(int j=0; j<n; ++j)
			if(v2[j][i] != v[j][i])
				for(int k=i+1; k<m; ++k)
					if(v2[j][i] == v[j][k])
						++cnt[k];

		int maxcnt = 0, iswap;
		for(int j=0; j<m; ++j)
			if(maxcnt < cnt[j])
				maxcnt = cnt[j], iswap = j;
		if(maxcnt != 0)
		{
			vec.pb(mp(i, iswap));
			for(int j=0; j<n; ++j)
				if((!ord && v[j][i] > v[j][iswap]) || (ord && v[j][i] < v[j][iswap]))
					swap(v[j][i], v[j][iswap]);
		}
		else ++i;
	}
	
	printf("%d\n", (int)vec.size());
	for(int i=0; i<(int)vec.size(); ++i)
	{
		if(!ord) printf("%d %d\n", vec[i].first + 1, vec[i].second + 1);
		else printf("%d %d\n", vec[i].second + 1, vec[i].first + 1);
	}

	return 0;
}
