#include<cstdio>
#include<cstring>
#include<utility>
using namespace std;

#define MAX 10010
#define mp make_pair

int main()
{
    int n, m, k, t, id, x, y, g[100][100];
    pair<int, int> turtle[MAX];
    char op[5];
    bool print = 0;

    while(scanf("%d %d %d %d", &n, &m, &k, &t) == 4)
    {
        memset(g, 0, sizeof(g));
        for(int i=0; i<k; ++i)
        {
            scanf("%d %d %d", &id, &x, &y);
            turtle[id] = mp(x, y);
            g[x][y] = 1;
        }

        for(int i=0; i<t; ++i)
        {
            scanf("%d %s", &id, op);
            pair<int, int> move;
            
            if(strcmp(op, "S") == 0) move = mp(1, 0);
            else if(strcmp(op, "N") == 0) move = mp(-1, 0);
            else if(strcmp(op, "W") == 0) move = mp(0, -1);
            else if(strcmp(op, "E") == 0) move  = mp(0, 1);
            else if(strcmp(op, "SE") == 0) move = mp(1, 1);
            else if(strcmp(op, "SW") == 0) move = mp(1, -1);
            else if(strcmp(op, "NW") == 0) move = mp(-1, -1);
            else if(strcmp(op, "NE") == 0) move = mp(-1, 1);
            

            x = turtle[id].first + move.first; 
            y = turtle[id].second + move.second; 
            if((x < 0 || x >= n || y < 0 || y >= m) || (g[x][y] != 0))
                continue;
            g[turtle[id].first][turtle[id].second] = 0;
            turtle[id] = mp(x, y);
            g[turtle[id].first][turtle[id].second] = 1;
        }

        for(int i=0; i<n; ++i, puts(""))
        {
        	int jmax = -1;
            for(int j=0; j<m; ++j)
                if(g[i][j])
                    jmax = j;
            for(int j=0; j<=jmax; ++j)
            {
                if(g[i][j]) printf("*");
                else printf(" ");
            }
        }
        puts("");
    }
        
    return 0;
}
