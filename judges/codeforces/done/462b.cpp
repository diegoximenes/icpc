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
#define MAX 100005

char v[MAX];
int cnt[50];

int main()
{
	int n, k;

	scanf("%d %d %s ", &n, &k, v);
	
	memset(cnt, 0, sizeof(cnt));
	for(int i=0; i<n; ++i) cnt[v[i] - 'A']++;
	sort(cnt, cnt + 'Z' - 'A' + 1);
	
	ll sol = 0;
	for(int i= 'Z' - 'A'; i>=0; --i)
	{
		sol += (ll)min(cnt[i], k) * (ll)min(cnt[i], k);
		k -= cnt[i];

		if(k <= 0) break;
	}

	cout << sol << endl;

	return 0;
}
