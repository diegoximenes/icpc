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
#define EPS 1e-9
#define MOD (int) (1e9 + 7)
#define MAX 2005

int n, k;
ll dp[MAX][MAX];

ll opt(int i, int x)
{
	if(i == k-1) return 1;
	ll &state = dp[i][x];
	if(state != -1) return state;
	
	ll sol = 0;
	for(int j=x; j<=n; j+=x) sol = (sol + opt(i+1, j))%MOD;

	return state = sol;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	
	scanf("%d %d", &n, &k);

	ll sol = 0;
	for(int i=1; i<=n; ++i) sol = (sol + opt(0, i))%MOD;
	
	cout << sol << endl;

	return 0;
}
