#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast_io ios::sync_with_stdio(false)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1);
const double EPS = 1e-9;

inline int cmp_double(double x, double y, double tol = EPS) {
    // (x < y): -1, (x == y): 0, (x > y): 1
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const ll MOD = 998244353LL;

#define MAX 100001

// (x / y) % MOD = (x * modinv(y, MOD)) % MOD
ll inv_mod(ll a, ll n) {
    ll b = n, x = 0, lastx = 1, aux;
    while (b) {
        ll q = a / b, r = a % b;
        a = b; b = r;
        aux = x;
        x = lastx - q * x, lastx = aux;
    }
    while (lastx < 0) lastx += n;
    return lastx;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int cnt_one = 0;
        for (int i = 0; i < n; ++i) {
            int a;
            scanf("%d", &a);
            if (a) {
                cnt_one++;
            }
        }

        ll out = 0;
        ll fact_len = 1;
        ll fact_rest = 1;
        for (ll i = 2; i <= n; ++i) {
            fact_rest = (i * fact_rest) % MOD;
        }
        for (int len = 1; len <= cnt_one; ++len) {
            fact_len = (fact_len * (cnt_one - len + 1)) % MOD;
            fact_rest = (fact_rest * inv_mod(n - len + 1, MOD)) % MOD;
            ll start_pos = n - len + 1;

            ll curr_out = (((start_pos * fact_len) % MOD) * fact_rest) % MOD;

            // printf("len=%d, fact_len=%lld, fact_rest=%lld, start_pos=%lld\n", len, fact_len, fact_rest, start_pos);
            out = (out + curr_out) % MOD;
        }
        printf("%lld\n", out);
    }

    return 0;
}
