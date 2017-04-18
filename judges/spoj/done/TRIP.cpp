#include<cstdio>
#include<cstring>
#include<deque>
#include<set>
#include<algorithm>
using namespace std;

#define mp make_pair
#define pb push_back
#define MAX 85

int n, m, t, dp[MAX][MAX];
char s1[MAX], s2[MAX];
set< deque<char> > out;
set< deque<char> >::iterator it;
set< pair< pair<int, int>, deque<char> > > buildMark;
deque<char> d;

int opt(int i, int j)
{
	if(i == n || j == m) return 0;
	int &state = dp[i][j];
	if(state != -1) return state;
	
	int sol;
	if(s1[i] == s2[j]) sol = 1 + opt(i+1, j+1);
	else sol = max(opt(i+1, j), opt(i, j+1));
	
	return state = sol;
}

void build(int i, int j)
{
	if(i == n || j == m) 
	{
		out.insert(d);
		return;
	}
	if(buildMark.find(mp(mp(i, j), d)) != buildMark.end()) return;
	
	if(s1[i] == s2[j]) d.pb(s1[i]), build(i+1, j+1), d.pop_back();
	else if(opt(i+1, j) > opt(i, j+1)) build(i+1, j);
	else if(opt(i, j+1) > opt(i+1, j)) build(i, j+1);
	else build(i+1, j), build(i, j+1);

	buildMark.insert(mp(mp(i, j), d));
}

int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf(" %s %s ", s1, s2);
		n = strlen(s1); m = strlen(s2);
		
		out.clear();	
		buildMark.clear();	
		memset(dp, -1, sizeof(dp));
		opt(0, 0);
		build(0, 0);
		
		for(it=out.begin(); it!=out.end(); ++it, puts(""))
			for(int j=0; j<(int)it->size(); ++j)
				putchar((*it)[j]);

		if(t != 0) puts("");
	}

	return 0;
}
