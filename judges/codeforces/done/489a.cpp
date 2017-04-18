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
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define EPS 1e-7
#define MAX 3005

int v[MAX], v2[MAX];

int main()
{
	int n;
	
	scanf("%d", &n);
	for(int i=0; i<n; ++i) scanf("%d", &v[i]), v2[i] = v[i];
	
	vector< pair<int, int> > out;
	sort(v2, v2+n);
	for(int i=0; i<n; ++i)
		for(int j=i; j<n; ++j)
			if(v2[i] == v[j])
			{
				out.pb(mp(i, j));
				swap(v[i], v[j]);
				break;
			}
	
	printf("%d\n", (int)out.size());
	for(int i=0; i<(int)out.size(); ++i) printf("%d %d\n", out[i].fi, out[i].se);

	return 0;
}
