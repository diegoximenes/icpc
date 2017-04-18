#include<cstdio>
#include<cstring>
#include<set>
#include<vector>
#include<cstdlib>
using namespace std;

#define mp make_pair
#define pb push_back
#define INF 1e9
#define MAX 1005
#define MMAX 105

int line[MAX];
pair<int, int> coin[MMAX];
int dp[MAX][MMAX];
int minline, maxline;
int t, n, m, l;
bool mark[MAX];
int dist[MAX];

int opt(int dist, int i)
{
    if(dist < 0) return INF;
    if(dist == 0) return 0;
    if(i == m) return INF;
    int &state = dp[dist][i];
    if(state != -1) return state;

    int sol1 = opt(dist, i+1);
    int sol2 = opt(dist - coin[i].second, i+1) + coin[i].first;
    
    return state = min(sol1, sol2);
}

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d %d", &n, &m, &l);
        
        minline = INF, maxline = -1;
        for(int i=0; i<n; ++i)
        {
            scanf("%d", &line[i]);
            minline = min(minline, line[i]);
            maxline = max(maxline, line[i]);
        }
        for(int i=0; i<m; ++i) scanf("%d %d", &coin[i].first, &coin[i].second);
        
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<=maxline; ++i) opt(i, 0);
        
        //for(int i=0; i<=maxline; ++i, puts(""))
         //   printf("%d ", opt(i, 0));

        vector< pair<int, int> > g[MAX];
        for(int i=0; i<n; ++i)
        {
            dist[line[i]] = INF;
            mark[line[i]] = 0;
            
            for(int j=0; j<n; ++j)
                if(i != j)
                {
                    int c = opt(abs(line[i] - line[j]), 0);
                    if(c <= l) g[line[i]].pb(mp(line[j], 1));
                }
        }
        
        /*for(int i=0; i<=maxline; ++i)
        {
            printf("u= %d: ", i);
            for(int j=0; j<(int)g[i].size(); ++j) printf("%d, ", g[i][j].first);
            puts("");
        }*/

        set< pair<int, int> > heap;
        dist[minline] = 0;
        heap.insert(mp(dist[minline], minline));
        while(!heap.empty())
        {
            int u = heap.begin()->second;
            heap.erase(heap.begin());
            mark[u] = 1;
            if(u == maxline) break;
                
           // printf("dijkstra: u= %d\n", u);

            for(int i=0; i<(int)g[u].size(); ++i)
            {
                int v = g[u][i].first, w = g[u][i].second;
                //printf("u= %d, v= %d, dist[u]= %d\n", u, v, dist[u]);
                if(!mark[v] && dist[v] > dist[u] + w)
                {
                    heap.erase(mp(dist[v], v));
                    dist[v] = dist[u] + w;
                    heap.insert(mp(dist[v], v));
                }
            }
        }
        //printf("maxline= %d, dist= %d\n", maxline, dist[maxline]); 
        if(!mark[maxline]) puts("-1");
        else printf("%d\n", dist[maxline]);
    }
    return 0;
}
