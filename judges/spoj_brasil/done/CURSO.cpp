#include<cstdio>
#include<algorithm>
#include<set>
#include<string>
#include<cstring>
#include<set>
#include<vector>
#include<map>
using namespace std;

#define MAXS 8
#define MAX 210
#define pb push_back

int main()
{
	int n, m, k, deg[MAX], nv, u, v;
	char s[MAXS];
	map<string, int> dic;
	map<int, string> dic2;
	set<int> heap;
	vector<int> g[MAX];
	vector<int> semester[MAX];

	while(scanf("%d %d", &n, &m) && n)
	{
		for(int i=0; i<MAX; ++i) g[i].clear();
		for(int i=0; i<MAX; ++i) semester[i].clear();
		dic.clear(); heap.clear();
		memset(deg, 0, sizeof(deg));
		nv = 0;

		for(int i=0; i<n; ++i)
		{
			scanf(" %s %d", s, &k);
			if(dic.find(s) == dic.end())
			{
				dic[s] = nv;
				dic2[nv] = s;
				u = nv++;
			}
			else 
				u = dic[s];
			deg[u] += k;

			for(int j=0; j<k; ++j)
			{
				scanf("%s", s);
				if(dic.find(s) == dic.end())
				{
					dic[s] = nv;
					dic2[nv] = s;
					v = nv++;
				}
				else
					v = dic[s];

				g[v].pb(u);
			}
		}
		
		int countSemester = 0;
		for(int i=0; i<nv; ++i)
			if(deg[i] == 0)
				heap.insert(i);
		while(!heap.empty())
		{
			for(int i=0; i<m && !heap.empty(); ++i)
			{
				u = *heap.begin();
				semester[countSemester].pb(u);
				heap.erase(u);
			}	
			for(int i=0; i<(int)semester[countSemester].size(); ++i)
			{
				u = semester[countSemester][i];
				for(int j=0; j<(int)g[u].size(); ++j)
				{
					v = g[u][j];
					--deg[v];
					if(deg[v] == 0) heap.insert(v);
				}
			}
			++countSemester;
		}

		printf("Formatura em %d semestres\n", countSemester);
		for(int i=0; i<countSemester; ++i)
		{
			vector<string> out;
			for(int j=0; j<(int)semester[i].size(); ++j)
				out.pb(dic2[semester[i][j]]);
			sort(out.begin(), out.end());
			
			printf("Semestre %d :", i+1);
			for(int i=0; i<(int)out.size(); ++i)
				printf(" %s", out[i].c_str());
			puts("");
		}
	}

	return 0;
}
