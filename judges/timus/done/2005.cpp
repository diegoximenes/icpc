#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

#define pb push_back

int main()
{
    int g[10][10];
    vector<int> v;
    v.pb(0); v.pb(1); v.pb(2); v.pb(3); v.pb(4);

    for(int i=0; i<5; ++i)
        for(int j=0; j<5; ++j)
            scanf("%d", &g[i][j]);

    int sol = 1e9;
    vector<int> out;
    do
    {
        if(v[3] == 2 || v[0] != 0 || v[4] != 4) continue;

        int lsol = 0;
        for(int i=0; i<4; ++i)
        {
            lsol += g[v[i]][v[i+1]];
            //printf("v[i]= %d, v[i+!]= %d, g[][]= %d\n", v[i], v[i+1], g[v[i]][v[i+1]]);
        }

        if(lsol < sol)
        {
            sol = lsol;
            out = v;
        }
        //break;
    }while(next_permutation(v.begin(), v.end()));

    printf("%d\n%d",sol, out[0]+1);
    for(int i=1; i<5; ++i) printf(" %d", out[i]+1);
    puts("");

    return 0;
}