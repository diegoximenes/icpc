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

int gcd (int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

#define MAX 200005
#define MAX2 100000

int n;
pair<int, int> v[MAX];
bitset<MAX2> is_prime;
vector<int> primes;

void sieve(ll n) {
    is_prime.set();
    is_prime[0] = is_prime[1] = 1;
    for (ll i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.pb(i);
            for (ll j = i * i; j <= n; j += i) {
                is_prime[j] = 0;
            }
        }
    }
}

vector<int> get_factors(ll n) {
    int pf_idx = 0;
    ll pf = primes[pf_idx];
    vector<int> factors;
    while (pf * pf <= n) {
        if (n % pf == 0) {
            factors.pb(pf);
        }
        while (n % pf == 0) {
            n /= pf;
        }
        pf = primes[++pf_idx];
    }
    if (n != 1) {
        factors.pb(n);
    }
    return factors;
}

bool solve(int f) {
    for (int i = 0; i < n; ++i) {
        if (v[i].fi % f != 0 && v[i].se % f != 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &v[i].fi, &v[i].se);
    }

    sieve(MAX2 - 1);
    vector<int> factors;

    bool can = 0;
    int sol;

    factors = get_factors(v[0].fi);
    for (int i = 0; i < (int) factors.size(); ++i) {
        can = solve(factors[i]);
        if (can) {
            sol = factors[i];
            break;
        }
    }

    if (!can) {
        factors = get_factors(v[0].se);
        for (int i = 0; i < (int) factors.size(); ++i) {
            can = solve(factors[i]);
            if (can) {
                sol = factors[i];
                break;
            }
        }
    }

    if (!can) {
       puts("-1");
    } else {
        printf("%d\n", sol);
    }

    return 0;
}
