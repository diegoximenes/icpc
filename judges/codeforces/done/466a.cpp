#include<cstdio>
#include<cctype>
#include<cstring>
#include<cmath>
#include<string>
#include<iostream>
#include<vector>
#include<list>
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
#define INF 0x3f3f3f3f
#define EPS 1e-9
#define MAX 1005

int dp[MAX];
int n, m, a, b;

int opt(int v)
{
	if(v <= 0) return 0;
	int &state = dp[v];
	if(state != - 1) return state;

	return state = min(a + opt(v-1), b + opt(v-m));
}

int main()
{
	scanf("%d %d %d %d", &n, &m, &a, &b);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", opt(n));

	return 0;
}
