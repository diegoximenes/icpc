#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL
const double PI = acos(-1);
const double EPS = 1e-9;

inline int cmp_double(double x, double y, double tol = EPS) {
    // (x < y): -1, (x == y): 0, (x > y): 1
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

#define MOD 1000000007LL
#define MAX 300005

ll a[MAX], pow2[MAX];

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    pow2[0] = 1;
    for (int i = 1; i < n; ++i) pow2[i] = (2LL * pow2[i - 1]) % MOD;

    sort(a, a + n);
    ll sol = 0;
    for (int i = 0; i < n; ++i) {
        ll add = pow2[i] - 1;
        if (add < 0) add += MOD;
        add = (add * a[i]) % MOD;

        ll sub = pow2[n - i - 1] - 1;
        if (sub < 0) sub += MOD;
        sub = (sub * a[i]) % MOD;

        sol = (sol + add) % MOD;
        sol = (sol - sub) % MOD;
        if (sol < 0) sol += MOD;
    }

    cout << sol << endl;

    return 0;
}
