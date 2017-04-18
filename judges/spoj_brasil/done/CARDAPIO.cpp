#include<cstdio>
#include<vector>
#include<map>
#include<string>
using namespace std;

#define MAX 2010
#define WHITE -1
#define pb push_back

int m, a, b;
map<string, int> dic;

//2 sat variables
vector<int> g[MAX], s;
int n, dfsCounter, numScc, low[MAX], num[MAX], component[MAX];
bool mark[MAX];

void tarjan(int u)
{
	low[u] = num[u] = dfsCounter++;
	s.pb(u);
	mark[u] = 1;

	for(int i=0; i<(int)g[u].size(); ++i)
	{
		int v = g[u][i];
		if(num[v] == WHITE)	tarjan(v);
		if(mark[v]) low[u] = min(low[u], low[v]);
	}

	if(low[u] == num[u])
	{
		numScc++;
		while(1)
		{
			int v = s.back(); s.pop_back(); mark[v] = 0;
			component[v] = numScc;
			if(u == v) break;
		}
	}
}

inline int notId(int i)
{
	return i + 1;
}

int main()
{
	char s1[30], s2[30];
	for(int tc=1; scanf("%d", &m) == 1; ++tc)
	{
		//clear graph
		for(int i=0; i<MAX; ++i) g[i].clear();
		dic.clear();
		n = 0;
		
		while(m--)
		{
			scanf(" %s %s", s1, s2);
			
			int aux1 = 0, aux2 = 0;
			if(s1[0] == '!') aux1 = 1;
			if(s2[0] == '!') aux2 = 1;
			
			if(dic.find(s1 + aux1) == dic.end()){ dic[s1 + aux1] = n, n += 2; }
			if(dic.find(s2 + aux2) == dic.end()){ dic[s2 + aux2] = n, n += 2; }

			a = dic[s1 + aux1];
			b = dic[s2 + aux2];
				
			if(s1[0] == '!' && s2[0] == '!') g[a].pb(notId(b)), g[b].pb(notId(a));
			else if(s1[0] == '!' && s2[0] != '!') g[a].pb(b), g[notId(b)].pb(notId(a));
			else if(s1[0] != '!' && s2[0] == '!') g[notId(a)].pb(notId(b)), g[b].pb(a);
			else g[notId(a)].pb(b), g[notId(b)].pb(a);
		}
		
		//tarjan
		s.clear();
		dfsCounter = numScc = 0;
		for(int i=0; i<MAX; ++i)
		{
			mark[i] = 0;
			low[i] = 0;
			component[i] = num[i] = WHITE;
		}
		for(int i=0; i<n; ++i)
			if(num[i] == WHITE)
				tarjan(i);

		//2sat verification
		bool sat = 1;
		for(int i=0; i<n && sat; i+=2) //for dont iterate over not
		{
			if(component[i] == component[notId(i)])
				sat = 0;
		}
		
		printf("Instancia %d\n", tc);
		(sat) ? puts("sim\n") : puts("nao\n");
	}

	return 0;
}
