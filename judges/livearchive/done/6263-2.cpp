#include<cstdio>
#include<list>
#include<vector>
using namespace std;

typedef long long ll;
#define pb push_back
#define NMAX 105
#define MMAX 50005

int n, m, t; 
ll a[NMAX], b[NMAX], c[NMAX];
list<int> part[MMAX];
list<int>::iterator it;
pair<ll, ll> king[MMAX];

inline bool parallel(int i, int j)
{
	if(a[i]*b[j] == b[i]*a[j]) return 1;
	return 0;
}

inline bool less(pair<ll, ll> p, int i)
{
	if(a[i]*p.first + b[i]*p.second + c[i] < 0) return 1;
	return 0;
}

int main()
{
	scanf("%d", &t);
	while(t--)
	{
		int np = 0;

		scanf("%d %d", &n, &m);
		for(int i=0; i<n; ++i)
		{
			scanf("%lld %lld %lld", &a[i], &b[i], &c[i]);
			for(int j=0; j<i; ++j) if(!parallel(i, j)) ++np;
		}
		for(int i=0; i<m; ++i) scanf("%lld %lld", &king[i].first, &king[i].second);
		
		int cnt = 1;
		for(int i=0; i<m; ++i) part[0].pb(i);
		for(int i=0; i<n; ++i)
		{
			int cntaux = cnt;
			for(int j=0; j<cntaux; ++j)
			{
				vector< list<int>::iterator > erase;
				
				bool hasLeft = 0, hasRight = 0;
				for(it=part[j].begin(); (!hasLeft || !hasRight) && it!=part[j].end(); ++it)
				{
					if(less(king[*it], i)) hasLeft = 1;
					else hasRight = 1;
				}
				if(!hasLeft || !hasRight) continue;
				
				for(it=part[j].begin(); it!=part[j].end(); ++it)
					if(less(king[*it], i))
						part[cnt].pb(*it), erase.pb(it);
	
				if(!erase.empty()) cnt++;
				for(int k=0; k<(int)erase.size(); ++k) part[j].erase(erase[k]);
			}
		}
				
		for(int i=0; i<=cnt; ++i) part[i].clear();

		puts( (cnt == np + n + 1) ? "PROTECTED" : "VULNERABLE");
	}

	return 0;
}
