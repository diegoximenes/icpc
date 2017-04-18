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
		
		vector< vector<int> > part;
		vector<int> aux;
		for(int i=0; i<m; ++i) aux.pb(i);
		part.pb(aux);
		for(int i=0; i<n; ++i)
		{
			int cnt = part.size();
			for(int j=0; j<cnt; ++j)
			{
				vector<int> left, right;

				for(int k=0; k<(int)part[j].size(); ++k)
				{
					if(less(king[part[j][k]], i)) left.pb(part[j][k]);
					else right.pb(part[j][k]);
				}
				if(left.empty() || right.empty()) continue;
				
				part[j] = left;
				part.pb(right);
			}
		}
				
		//printf("n= %d, np= %d, cnt= %d\n", n, np, part.size());
		puts( ((int)part.size() == np + n + 1) ? "PROTECTED" : "VULNERABLE");
	}

	return 0;
}
