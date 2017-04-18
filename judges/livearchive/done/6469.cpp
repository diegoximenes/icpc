#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAX 18
#define MASKMAX (1 << 17)

int n, k;
ll dp[MASKMAX], fat[MAX];

void printMask(int mask)
{
    for(int i=18; i>=0; --i)
    {
        if(mask & (1 << i)) putchar('1');
        else putchar('0');
    }
}

ll opt(int mask)
{
    int pos = __builtin_popcount(mask);
    if(pos == k) return (fat[n-k]);
    
    ll &state = dp[mask];
    if(state != -1) return state;
    
    ll sol = 0;
    for(int i=0; i<n; ++i)
        if(i != pos && !(mask & (1 << i)))
            sol += opt(mask | (1 << i));
    
    //cout << "pos= " << pos << ", state= " << sol << endl;
    
    //printMask(mask);
    //cout << " = " << sol << endl;

    return state = sol;
}

int main()
{
    int t, tc;
    
    fat[0] = 1;
    for(int i=1; i<18; ++i) fat[i] = fat[i-1] * (ll)i;
    
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d %d", &tc, &n, &k);
        
        memset(dp, -1, sizeof(dp));
        //printf("%d %lld\n", tc, opt(0));
        cout << tc << " " << opt(0) << endl;
    }

    return 0;
}
