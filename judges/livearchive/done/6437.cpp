#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define MAX 205

vector< pair<int, int> > g[MAX];
int cost[MAX];
bool mark[MAX];

int main()
{
    int t, n, m, k;

    scanf("%d", &t);
    for(int tc=0; tc<t; ++tc)
    {
        scanf("%d %d %d", &n, &m, &k);
        for(int i=0; i<=n; ++i)
        {
            cost[i] = INF;
            mark[i] = 0;
            g[i].clear();
        }

        set< pair<int, int> > heap;

        for(int i=0; i<k; ++i)
        {
            int u;
            scanf("%d", &u); --u;
            cost[u] = 0;
            heap.insert(mp(cost[u], u));
        }

        while(m--)
        {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            --u; --v;
            g[u].pb(mp(v, w));
            g[v].pb(mp(u, w));
        }
        
        int mstCost = 0;
        while(!heap.empty())
        {
            int u = heap.begin()->second;
            mark[u] = 1;
            mstCost += cost[u];
            heap.erase(heap.begin());
            
            for(int i=0; i<(int)g[u].size(); ++i)
            {
                int v = g[u][i].first, w = g[u][i].second;
                if(!mark[v] && cost[v] > w)
                {
                    heap.erase(mp(cost[v], v));
                    cost[v] = w;
                    heap.insert(mp(cost[v], v));
                }
            }
        }

        printf("Case #%d: %d\n", tc+1, mstCost);
    }

    return 0;
}
