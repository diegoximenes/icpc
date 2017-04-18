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
#define MAX 500050

int n;
ll v[MAX], cumRight[MAX], cumLeft[MAX];

int main()
{
	map<ll, int> cnt;

	scanf("%d", &n);
	cumRight[n+1] = cumLeft[0] = 0;
	for(int i=1; i<=n; ++i) cin >> v[i], cumLeft[i] = cumLeft[i-1] + v[i];
	for(int i=n; i>=1; --i)
	{
		cumRight[i] = cumRight[i+1] + v[i];
		if(cnt.find(cumRight[i]) == cnt.end()) cnt[cumRight[i]] = 1;
		else cnt[cumRight[i]]++;
	}
	
	ll sol = 0;
	
	cnt[cumRight[0]]--;
	for(int i=1; i<n-1; ++i)
	{
		cnt[cumRight[i+1]]--;
		if(cumRight[i+1]%2 == 0 && cumRight[i+1]/2 == cumLeft[i]) sol += cnt[cumLeft[i]];
	}
	
	cout << sol << endl;

	return 0;
}
