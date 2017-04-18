#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
using namespace std;

#define pb push_back
#define mp make_pair
#define MAX 100010
#define INF (int) 1e9

vector< pair<int, int> > compartment[MAX];
vector< pair<int, int> >::iterator it;
int dp[MAX], next[MAX];

int main()
{
	int t;
	map<int, int> dic;
	
	scanf("%d", &t);
	while(t--)
	{
		int countComp = 0, n, k, p, s, f;
		
		dic.clear();
		scanf("%d %d", &n, &k);
		for(int i=0; i<n ;++i)
		{
			scanf("%d %d %d", &s, &f, &p);
			if(dic.find(p) == dic.end()) dic[p] = countComp++; 
			compartment[dic[p]].pb(mp(s, f));	
		}
		
		int sol = 0;
		for(int i=0; i<countComp; ++i)
		{
			sort(compartment[i].begin(), compartment[i].end());
			
			for(int j=0; j<(int)compartment[i].size(); ++j)
			{
				it = upper_bound(compartment[i].begin(), compartment[i].end(), mp(compartment[i][j].second - 1, INF));
				if(it == compartment[i].end()) next[j] = -1;
				else next[j] = it - compartment[i].begin();
			}
			
			dp[(int)compartment[i].size()-1] = 1;
			for(int j=compartment[i].size()-2; j>=0; --j)
			{
				dp[j] = dp[j+1];
				if(next[j] != -1) dp[j] = max(dp[j], 1 + dp[next[j]]);
			}
			sol += dp[0];

			compartment[i].clear();
		}
		
		printf("%d\n", sol);
	}

	return 0;
}
