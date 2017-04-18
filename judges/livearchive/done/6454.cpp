
    #include<cstdio>
    #include<cstring>
    #include<algorithm>
    using namespace std;

    #define NMAX 16
    #define MAX (1 << 16)
    #define INF 0x3f3f3f3f

    #define mp make_pair

    int dic[205][205];
    char g[205][205];
    int dp[MAX], n, m, cnt;
    const int neigh[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    pair<int, int> pnt[NMAX];

    inline bool can(int i, int j)
    {
        if(i>=0 && i<n && j>=0 && j<m) return 1;
        return 0;
    }

    int opt(int mask)
    {
        int cntIluminated = 0;
        bool iluminated[NMAX], fail;
        memset(iluminated, 0, sizeof(iluminated));

        fail = 0;
        for(int i=0; i<cnt; ++i)
            if(mask & (1 << i))
            {
                int x = pnt[i].first, y = pnt[i].second;

                if(iluminated[dic[x][y]] == 0) ++cntIluminated;
                iluminated[dic[x][y]] = 1;

                for(int k=0; k<2; ++k)
                {
                    int x1 = x + neigh[k][0], y1 = y + neigh[k][1];
                    if(can(x1, y1))
                    {
                        if(g[x1][y1] == '.')
                        {
                            if(iluminated[dic[x1][y1]] == 0) ++cntIluminated;
                            iluminated[dic[x1][y1]] = 1;
                        }
                        else fail = 1;
                    }
                }
            }
        if(!fail && cntIluminated == cnt) return 0;

        //printf("mask= %d, cntIluminated= %d\n", mask, cntIluminated);

        int &state = dp[mask];
        if(state != -1) return state;

        //rotate
        for(int i=0; i<cnt; ++i)
            if(mask & (1 << i))
            {
                int x = pnt[i].first, y = pnt[i].second;

                for(int k=0; k<4; ++k)
                {
                    memset(iluminated, 0, sizeof(iluminated));
                    cntIluminated = 0;
                    fail = 0;

                    if(iluminated[dic[x][y]] == 0) ++cntIluminated;
                    iluminated[dic[x][y]] = 1;

                    for(int l=0; l<2; ++l)
                    {
                        int x1 = x + neigh[(k+l)%4][0];
                        int y1 = y + neigh[(k+l)%4][1];

                        if(can(x1, y1))
                        {
                            if(g[x1][y1] == '.')
                            {
                                if(iluminated[dic[x1][y1]] == 0) ++cntIluminated;
                                iluminated[dic[x1][y1]] = 1;
                            }
                            else fail = 1;//, printf("mask= %d, k= %d, x=%d, y= %d, x1= %d, y1= %d\n", mask, k, x, y, x1, y1);
                        }
                    }

                    for(int i2=0; i2<cnt; ++i2)
                        if(i2 != i && (1 << i2) & mask)
                        {
                            int x2 = pnt[i2].first, y2 = pnt[i2].second;

                            if(iluminated[dic[x2][y2]] == 0) ++cntIluminated;
                            iluminated[dic[x2][y2]] = 1;

                            for(int l=0; l<2; ++l)
                            {
                                int x1 = x2 + neigh[l][0];
                                int y1 = y2 + neigh[l][1];

                                if(can(x1, y1))
                                {
                                    if(g[x1][y1] == '.')
                                    {
                                        if(iluminated[dic[x1][y1]] == 0) ++cntIluminated;
                                        iluminated[dic[x1][y1]] = 1;
                                    }
                                    else fail = 1;
                                }
                            }
                        }
                    //printf("mask= %d, k= %d, cntIluminated= %d, fail= %d, i= %d\n", mask, k, cntIluminated, fail, i);

                    if(!fail && cntIluminated == cnt) return state = 0;
                }
            }

        if(__builtin_popcount(mask) == cnt) return INF;

        int sol = INF;
        for(int i=0; i<cnt; ++i)
            if(!(mask & (1 << i)))
                sol = min(sol, 1 + opt(mask | (1 << i)));

        return state = sol;
    }

    int main()
    {
        while(scanf("%d %d", &n, &m) && n)
        {
            gets(g[0]);
            for(int i=0; i<n; ++i) gets(g[i]);

            cnt = 0;
            for(int i=0; i<n; ++i)
                for(int j=0; j<m; ++j)
                    if(g[i][j] == '.')
                    {
                        pnt[cnt] = mp(i, j);
                        dic[i][j] = cnt++;
                    }

            memset(dp, -1, sizeof(dp));
            int sol = opt(0);
            if(sol >= INF) puts("-1");
            else printf("%d\n", sol);
        }

        return 0;
    }

