#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define MAX 15

int g[MAX][MAX];

int main()
{
    int  n, m, c;
    while(scanf("%d %d %d", &n, &m, &c) == 3)
    {
        vector< pair<int, int> > v;
        for(int i=0; i<c; ++i) 
        {
            int x; scanf("%d", &x);
            v.pb(mp(x, i+1));
        }
        sort(v.begin(), v.end());
        
        bool decj = 0;
        int k = 0, j = -1, i = n;
        while(1)
        {
            if(j == -1) i--, decj = 0, j = 0;
            if(j == m) i--, decj = 1, j = m-1;
            if(i < 0) break;

            if(v[k].first == 0) k++;
            
            //printf("i= %d, j= %d, k= %d, second= %d\n", i, j, k, v[k].second);
            
            g[i][j] = v[k].second;
            v[k].first--;
            if(decj) j--;
            else j++;
        }

        for(int i=n-1; i>=0; --i, puts(""))
            for(int j=0; j<m; ++j)
                printf("%d", g[i][j]);
    }

    return 0;
}
