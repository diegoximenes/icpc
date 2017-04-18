#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

#define MAX 35

int g[MAX][MAX], g2[MAX][MAX], gr[MAX][MAX];

int main()
{
    int n;

    while(scanf("%d", &n) && n)
    {
        for(int i=0; i<n; ++i)
            for(int j=0; j<n; ++j)
                scanf("%d", &g[i][j]);
        for(int i=0; i<n; ++i)
            for(int j=0; j<n; ++j)
                scanf("%d", &g2[i][j]);

        int sol = 0;
        for(int r=0; r<5; ++r)
        {
            int lsol = 0;
            for(int i=0; i<n; ++i)
                for(int j=0; j<n; ++j)
                    if(g[i][j] == g2[i][j])
                        lsol++;
            sol = max(sol, lsol);
            
            for(int i=0; i<n; ++i)
                for(int j=0; j<n; ++j)
                    gr[n-j-1][i] = g[i][j];
            
            memcpy(g, gr, sizeof(g));
        }

        printf("%d\n", sol);
    }

    return 0;
}
