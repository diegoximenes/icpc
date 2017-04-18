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
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair
#define INF 1e9
#define MAX 10005

int n, k, a[MAX];	

int solve(int i, int height, vector< pair<bool, pair<int, int> > > &out)
{
	if(i == n) return 0;

	if(height + k == a[i]) return solve(i+1, height + k, out);

	if(height + k > a[i]) out.pb(mp(1, mp(i, height + k - a[i])));
	else out.pb(mp(0, mp(i, a[i] - (height + k))));

	return 1 + solve(i+1, height + k, out);
}

int main()
{

	scanf("%d %d", &n, &k);
	for(int i=0; i<n; ++i) scanf("%d", &a[i]);
	
	vector< pair<bool, pair<int, int> > > out, lout;
	int sol = solve(1, a[0], out);
	for(int i=1; i<=1000; ++i) 
		if(i != a[0])
		{
			lout.clear();
			
			if(i > a[0]) lout.pb(mp(1, mp(0, i - a[0])));
			else lout.pb(mp(0, mp(0, a[0] - i)));
			
			int lsol = 1 + solve(1, i, lout);
			if(sol > lsol) sol = lsol, out = lout;
		}
	
	printf("%d\n", sol);
	for(int i=0; i<sol; ++i)
	{
		printf("%c ", (out[i].first) ? '+' : '-');
		printf("%d %d\n", out[i].second.first + 1, out[i].second.second);
	}

	return 0;
}
