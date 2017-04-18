#include<cstdio>
#include<ctime>
#include<cctype>
#include<cstring>
#include<string>
#include<map>
#include<queue>
#include<vector>
using namespace std;

#define mp make_pair
#define pb push_back
#define MAX 1010
#define MAX2 6
#define MAX3 2010

int t, n, cntv = 0, lenp, dp[MAX][MAX3];
char s1[MAX2], s2[MAX2], s3[MAX2], p[MAX3];
vector<int> g[MAX];
map<int, string> dic2;
map<int, string>::iterator it;
map<string, int> dic;

int preOrder(int v, int indp)
{
	int indpLast = indp;
	if(dp[v][indp] != -1) return dp[v][indp];

	if(dic2.find(v) != dic2.end())
	{
		string s = dic2[v];
		for(int i=0; indp < lenp && i<(int)s.size(); ++i)
			if(s[i] == p[indp]) 
				++indp;
	}
	else
		for(int i=0; i<(int)g[v].size(); ++i)
			indp = preOrder(g[v][i], indp);

	return dp[v][indpLast] = indp;
}

int main()
{
	scanf("%d", &t);
	while(t--)
	{
		memset(dp, -1, sizeof(dp));
		for(int i=0; i<cntv; ++i) g[i].clear();
		cntv = 0;
		dic.clear(); dic2.clear();
			
		scanf("%d", &n);
		for(int i=0; i<n; ++i)
		{
			scanf(" %s = %s", s1, s2);
			if(!islower(s2[0]))
			{
				scanf(" + %s", s3);
				
				if(dic.find(s1) == dic.end()) dic[s1] = cntv++;
				if(dic.find(s2) == dic.end()) dic[s2] = cntv++;
				if(dic.find(s3) == dic.end()) dic[s3] = cntv++;

				g[dic[s1]].pb(dic[s2]);
				g[dic[s1]].pb(dic[s3]);
			}
			else
			{
				if(dic.find(s1) == dic.end()) dic[s1] = cntv++;
				dic2[dic[s1]] = s2;
			}
		}
		
		scanf(" %s %s", s1, p);
		lenp = strlen(p);

		if(preOrder(dic[s1], 0) == lenp) puts("YES");
		else puts("NO");
	}

	return 0;
}
