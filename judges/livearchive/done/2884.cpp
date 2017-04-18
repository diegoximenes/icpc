#include<bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define MAX 125

int n, v[MAX], dp[MAX][MAX];
double r;

int opt(int i, int j)
{
    if(i > j) return 0;
    if((double)v[j]/(double)v[i] <= r) return 1;
    int &state = dp[i][j];
    if(state != -1) return state;

    int sol = INF;
    for(int k=i; k<j; ++k) sol = min(sol, opt(i, k) + opt(k+1, j));

    return state = sol;
}

int main()
{
    while(scanf("%d %lf", &n, &r) && n)
    {
        for(int i=0; i<n; ++i) scanf("%d %*d", &v[i]);
        sort(v, v+n);
        
        memset(dp, -1, sizeof(dp));
        printf("%d\n", opt(0, n-1));
    }

    return 0;
}
