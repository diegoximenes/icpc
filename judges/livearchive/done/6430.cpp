#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAX 1000005
#define INF 0x3f3f3f3f3f3f3f3fLL

int n;
ll dp[MAX][2][2];
ll a[MAX], b[MAX], c[MAX];

ll opt(int i, int neigh, int select)
{
    if(i == n)
    {
        if(select) return -INF;
        return 0;
    }
    ll &state = dp[i][neigh][select];
    if(state != -1) return state;

    ll sol = -INF;
    if(select)
    {
        ll sol1, sol2;
        if(neigh == 0)
        {
            sol1 = a[i] + opt(i+1, 1, 0);
            sol2 = b[i] + opt(i+1, 1, 1);
        }
        else
        {
            sol1 = b[i] + opt(i+1, 1, 0);
            sol2 = c[i] + opt(i+1, 1, 1);
        }
        sol = max(sol, max(sol1, sol2));
    }
    else sol = max(opt(i+1, 0, 1), opt(i+1, 0, 0));

    return state = sol;
}

int main()
{
    while(scanf("%d", &n) == 1)
    {
        for(int i=0; i<n; ++i) cin >> a[i] >> b[i] >> c[i];
       
        dp[n][0][0] = dp[n][1][0] = 0;
        dp[n][0][1] = dp[n][1][1] = -INF;
        for(int i=n-1; i>=0; --i)
            for(int neigh=0; neigh<=1; ++neigh)
                for(int select=0; select<=1; ++select)
                {
                    ll sol = -INF;
                    if(select)
                    {
                        ll sol1, sol2;
                        if(neigh == 0)
                        {
                            sol1 = a[i] + dp[i+1][1][0];
                            sol2 = b[i] + dp[i+1][1][1];
                        }
                        else
                        {
                            sol1 = b[i] + dp[i+1][1][0];
                            sol2 = c[i] + dp[i+1][1][1];
                        }
                        sol = max(sol, max(sol1, sol2));
                    }
                    else sol = max(dp[i+1][0][1], dp[i+1][0][0]);

                    dp[i][neigh][select] = sol;
                 }
        
        cout << max(dp[0][0][0], dp[0][0][1]) << endl;
    }

    return 0;
}
