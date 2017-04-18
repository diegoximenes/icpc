#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAX 105*105
#define MOD 10000000000007LL

ll mult[MAX], fat[MAX];

int main()
{
    ll t, n, l, u;
    
    cin >> t;
    for(int tc=1; tc<=t; ++tc)
    {
        cin >> n >> l >> u;
        
        mult[1] = n*n;
        for(int i=2; i<=n*n; ++i) mult[i] = (mult[i-1] * (n*n - (ll)(i-1)))%MOD;  

        ll sol = 0;
        for(int i=l; i<=u; ++i) sol = (sol + mult[i]) % MOD;
        
        cout << "Case " << tc << ": " << sol << endl;
    }

    return 0;
}
