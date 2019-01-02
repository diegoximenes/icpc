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

#define MAX 1000005

const ll mod = 998244353;
ll n;
ll fat[MAX];

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
    cin >> n;

    fat[0] = 1;
    for (ll i = 1; i <= n; ++i) {
        fat[i] = (fat[i - 1] * i) % mod;
    }

    ll sol = fat[n];
    for (ll i = 1; i <= n; ++i) {
        ll left =  (fat[n] * inv_mod(fat[n - i], mod)) % mod;
        ll right =  fat[n - i] - 1;
        if (right < 0) {
            right += mod;
        }
        sol = (sol + (left * right) % mod) % mod;
    }

    cout << sol << endl;

    return 0;
}
