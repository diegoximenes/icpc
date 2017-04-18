#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
#define MAX 105

char g[MAX][MAX];
int dist[MAX][MAX], n, m;
bool mark[MAX][MAX];
const int neigh[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

inline bool can(int i, int j)
{
    if(i>=0 && i<n && j>=0 && j<m) return 1;
    return 0;
}

int bfs(pair<int, int> s, pair<int, int> t)
{
    queue< pair<int, int> > q;
    q.push(s);
    memset(mark, 0, sizeof(mark));
    memset(dist, INF, sizeof(dist));
    mark[s.first][s.second] = 1;
    dist[s.first][s.second] = 0;
    while(!q.empty())
    {
        pair<int, int> u = q.front(); q.pop();
        if(u == t) break;

        for(int k=0; k<4; ++k)
        {
            int i = u.first + neigh[k][0], j = u.second + neigh[k][1];
            if(can(i, j) && !mark[i][j] && g[i][j] == '.')
            {
                mark[i][j] = 1;
                dist[i][j] = dist[u.first][u.second] + 1;
                q.push(mp(i, j));
            }
        }
    }

    return dist[t.first][t.second];
}

int main()
{
    while(scanf("%d %d", &n, &m) && n)
    {
        gets(g[0]);
        for(int i=0; i<n; ++i) gets(g[i]);

        pair<int, int> start;
        for(int i=0; i<n; ++i)
            for(int j=0; j<m; ++j)
                if(g[i][j] == '@')
                    start = mp(i, j), g[i][j] = '.';

        int k, x, y;
        scanf("%d", &k);
        vector< pair<int, int> > v; 
        vector<int> vperm;
        for(int i=0; i<k; ++i) scanf("%d %d", &x, &y), v.pb(mp(x-1, y-1)), vperm.pb(i);
    
        int sol = INF;
        do
        {
            int lsol = bfs(start, v[vperm[0]]);
            if(lsol == INF) continue;
           	
            for(int i=0; i<(int)vperm.size() - 1; ++i) 
            {
                int aux = bfs(v[vperm[i]], v[vperm[i+1]]);
                if(aux == INF)
                {
                    lsol = INF;
                    break;
                }
                lsol += aux;
            }
			
            sol = min(sol, lsol);
			
        }while(next_permutation(vperm.begin(), vperm.end()));
        
        if(sol == INF) puts("-1");
        else printf("%d\n", sol);
    }

    return 0;
}
