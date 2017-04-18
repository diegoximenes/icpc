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

int main()
{
	ll n, cnt = 0, x, sol = 0;
	cin >> n;
	for(int i=0; i<n; ++i)
	{
		cin >> x;
		cnt += x;
		if(!x) sol += cnt;
	}

	cout << sol << endl;

	return 0;
}
