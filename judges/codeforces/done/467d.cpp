#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define INF 0x3f3f3f3f
#define WHITE -1
#define MAX 500005

int num[MAX], low[MAX], dfsCounter, numScc, scc[MAX];
bool visited[MAX];
ll dp[MAX], dp2[MAX];
vector<int> g2[MAX];

int n;
vector<int> g[MAX];

int nEssay, nSin, essay[MAX];
string s1, s2;
map<string, int> dic;
ll cntR[MAX], cntRScc[MAX], len[MAX], lenScc[MAX];

deque<int> s;
void tarjan(int u)
{
	low[u] = num[u] = dfsCounter++;
	s.pb(u);
	visited[u] = 1;

	for(int i=0; i<(int)g[u].size(); ++i)
	{
		int v = g[u][i];
		if(num[v] == WHITE) tarjan(v);
		if(visited[v]) low[u] = min(low[u], low[v]);
	}

	if(low[u] == num[u])
	{
		cntRScc[numScc] = lenScc[numScc] = INF;
		while(1)
		{
			int v = s.back(); s.pop_back();
			scc[v] = numScc;
			visited[v] = 0;	

			if(cntRScc[numScc] == cntR[v]) lenScc[numScc] = min(lenScc[numScc], len[v]);
			else if(cntR[v] < cntRScc[numScc]) cntRScc[numScc] = cntR[v], lenScc[numScc] = len[v];

			if(u == v) break;
		}
		++numScc;
	}
}

void toLower(string &s) { for(int i=0; i<(int)s.size(); ++i) s[i] = tolower(s[i]); }

ll countR(string &s)
{
	ll cnt = 0;
	for(int i=0; i<(int)s.size(); ++i) cnt += (s[i] == 'r');
	return cnt;
}

ll opt(int u)
{
	ll &state = dp[u];
	if(state != -1) return state;
	
	state = cntRScc[u];
	for(int i=0; i<(int)g2[u].size(); ++i)
	{
		int v = g2[u][i];
		state = min(state, opt(v));
	}

	return state;
}

ll opt2(int u)
{
	ll &state = dp2[u];
	if(state != -1) return state;
	
	state = INF;
	if(opt(u) == cntRScc[u]) state = lenScc[u];
	for(int i=0; i<(int)g2[u].size(); ++i)
	{
		int v = g2[u][i];
		if(opt(u) == opt(v)) state = min(state, opt2(v));
	}

	return state;
}

void insert(string &s)
{
	if(dic.find(s) != dic.end()) return;
	dic[s] = n++;
	cntR[dic[s]] = countR(s);
	len[dic[s]] = s.size();
}

int main()
{	
	n = 0;
	scanf("%d", &nEssay);
	for(int i=0; i<nEssay; ++i)
	{
		cin >> s1; toLower(s1);
		insert(s1);
		essay[i] = dic[s1];
	}
	scanf("%d", &nSin);
	for(int i=0; i<nSin; ++i)
	{
		cin >> s1 >> s2; toLower(s1); toLower(s2);
		insert(s1); insert(s2);
		g[dic[s1]].pb(dic[s2]);
	}

	for(int i=0; i<n; ++i) num[i] = WHITE, low[i] = 0, visited[i] = 0;
	dfsCounter = numScc = 0;
	for(int i=0; i<n; ++i)
		if(num[i] == WHITE)
			tarjan(i);
	
	for(int u=0; u<n; ++u)
		for(int i=0; i<(int)g[u].size(); ++i)
		{
			int v = g[u][i];
			if(scc[u] == scc[v]) continue;
			
			g2[scc[u]].pb(scc[v]);
		}
	
	for(int i=0; i<numScc; ++i) dp[i] = dp2[i] = -1;
	
	ll sol1 = 0, sol2 = 0;
	for(int i=0; i<nEssay; ++i) sol1 += opt(scc[essay[i]]), sol2 += opt2(scc[essay[i]]);
	
	cout << sol1 << " " << sol2 << endl;

	return 0;

}
