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

#define ll long long
#define pb push_back
#define mp make_pair
#define INF 1e9
#define MAX 100010

int main()
{
	int n, cnt = 0;
	ll v[MAX], maxd = -1, x0, x1, mind = INF;
	vector< pair<ll, ll> > delta;
	map<ll, int> mark;
	
	scanf("%d", &n);	
	for(int i=0; i<n; ++i) cin >> v[i];
	sort(v, v+n);
	
	int cntSame = 1;
	for(int i=1; i<n; ++i)
	{
		ll d = v[i] - v[i-1];
		if(mark.find(d) == mark.end())
		{
			if(maxd < d)
			{
				x0 = v[i-1]; x1 = v[i];
				maxd = d;
			}
			mind = min(d, mind);
			mark[d] = 1;
			delta.pb(mp(v[i], v[i-1]));
			++cnt;
		}
		else mark[d]++;
		
		if(v[i] == v[i-1]) ++cntSame;
	}
	
	if(n == 1)
	{
		puts("-1");
		return 0;
	}

	if(n == 2 && v[0] != v[1])
	{
		ll d1 = (v[1] - v[0])/2, d2 = v[1] - v[0];
		
		if(v[0] + d1 - v[0] == v[1] - (v[0] + d1))
		{
			cout << "3" << endl;
			cout << v[0] - d2 << " " <<  v[0] + d1 << " " << v[1] + d2 << endl;
			return 0;
		}
	}

	if(cnt > 2)
	{
		puts("0");
		return 0;
	}

	if(cnt == 1)
	{
		ll d = (delta[0].first - delta[0].second);

		if(d == 0)
		{
			cout << "1" << endl;
			cout << v[0] << endl;
			return 0;
		}

		cout << "2" << endl;
		cout << v[0] - d  << " "  << v[n-1] + d << endl;
	}
	else if(cnt == 2)
	{
		if(mind == 0 || mark[maxd] > 1 || (x1 - x0 - mind != mind))
		{
			puts("0");
			return 0;
		}

		cout << "1" << endl;
		cout << x0 + mind << endl;
	}

	return 0;
}
