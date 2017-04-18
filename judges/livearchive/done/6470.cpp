#include<bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define MAX 105
#define mp make_pair

int dp[MAX][MAX][MAX][2];
pair<int, int> out[MAX][MAX][MAX][2];

int opt(int l, int m, int u, int turn)
{
    int sol = -INF;
    if(!turn) sol = INF;
    if(l == 1 && m == 0 && u == 0) return sol;

    pair<int, int> &lout = out[l][m][u][turn];
    int &state = dp[l][m][u][turn];
    if(state != -1) return state;
        
    for(int i=1; i<l; ++i)
    {
        int aux = opt(l-i, min(l-i, m), min(l-i, u), 1-turn);
        if(turn)
        {
            sol = max(sol, aux);
            if(sol == INF)
            {
                lout = mp(1, l-i+1);
                return state = sol;
            }
        }
        else
        {
            sol = min(sol, aux);
            if(sol == -INF) return state = sol;
        }
    }

    for(int i=1; i<=m; ++i)
    {
        int aux = opt(l, m-i, min(u, m-i), 1-turn);
        if(turn)
        {
            sol = max(sol, aux);
            if(sol == INF)
            {
                lout = mp(2, m-i+1);
                return state = sol;
            }
        }
        else
        {
            sol = min(sol, aux);
            if(sol == -INF) return state = sol;
        }
    }

    for(int i=1; i<=u; ++i)
    {
        int aux = opt(l, m, u-i, 1-turn);
        if(turn)
        {
            sol = max(sol, aux);
            if(sol == INF)
            {
                lout = mp(3, u-i+1);
                return state = sol;
            }
        }
        else
        {
            sol = min(sol, aux);
            if(sol == -INF) return state = sol;
        }
    }

    //printf("l= %d, m= %d, u= %d, turn= %d, sol= %d\n", l, m, u, turn, sol);

    return state = sol;
}

int main()
{
    int t, tc, l, m, u;
    
    memset(dp, -1, sizeof(dp));

    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d %d %d", &tc, &l, &m, &u);
        
        int sol = opt(l, m, u, 1);

        printf("%d ", tc);
        
        if(l == 0)
        {
            puts("L");
            continue;
        }

        if(sol == -INF) puts("L");
        else printf("W %d %d\n", out[l][m][u][1].second, out[l][m][u][1].first);
    }

    return 0;
}
