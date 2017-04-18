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

int main()
{
	int n;
	char cards[15], g[15][15];
	vector< pair<int, int> > out;
	
	scanf("%d", &n);
	while(n--)
	{
		out.clear();
		scanf(" %s", cards);

		for(int a=1; a<=12; ++a)
			if(12%a == 0)
			{
				int b = 12/a;

				int k = 0;
				for(int i=0; i<a; ++i)
					for(int j=0; j<b; ++j)
						g[i][j] = cards[k++];
				
				for(int j=0; j<b; ++j)
				{
					bool can = 1;
					for(int i=0; i<a; ++i)
						if(g[i][j] != 'X')
							can = 0;
					if(can) 
					{
						out.pb(mp(a, b));
						break;
					}
				}
			}

		sort(out.begin(), out.end());
		printf("%d", (int)out.size());
		for(int i=0; i<(int)out.size(); ++i) printf(" %dx%d", out[i].first, out[i].second);
		puts("");
	}

	return 0;
}
