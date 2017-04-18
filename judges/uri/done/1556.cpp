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
#define MAX 1005

bool mark[40];
int l[MAX];
char s[MAX];

int main()
{
	while(scanf("%s", s) == 1)
	{
		memset(l, 0, sizeof(l));
		memset(mark, 0, sizeof(mark));
		vector< pair< vector<char>, int> > out;
		int n = strlen(s);
		for(int i=0; i<n; ++i)
		{
			int upper = out.size();
			for(int j=0; j<upper; ++j)
				if(l[s[i] - 'a'] <= out[j].second)
				{
					vector<char> v = out[j].first;
					v.pb(s[i]);
					out.pb(mp(v, i));
				}
			
			if(!mark[s[i] - 'a']) 
			{
				vector<char> v; v.pb(s[i]);
				out.pb(mp(v,i));
				mark[s[i] - 'a'] = 1;
			}
				
			l[s[i] - 'a'] = i;
		}
		
		sort(out.begin(), out.end());
		for(int i=0; i<(int)out.size(); ++i, puts(""))
			for(int j=0; j<(int)out[i].first.size(); ++j)
		 		printf("%c", out[i].first[j]);
		puts("");
	}

	return 0;
}
