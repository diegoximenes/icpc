#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

#ifdef LOCAL
#define debug(...)                    \
    {                                 \
        fprintf(stderr, __VA_ARGS__); \
        fflush(stderr);               \
    }
#else
#define debug(...)
#endif

const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1);
const double EPS = 1e-9;

inline int cmp_double(double x, double y, double tol = EPS) {
    // (x < y): -1, (x == y): 0, (x > y): 1
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

template <class T>
inline void print_array(T *v, int n) {
    if (n > 0) {
        cout << v[0];
    }
    for (int i = 1; i < n; ++i) {
        cout << " " << v[i];
    }
    cout << endl;
}

template <class T>
inline void read_array(T *v, int n, int start = 0) {
    for (int i = start; i < start + n; ++i) {
        cin >> v[i];
    }
}

template <class T>
inline void print_vector(const vector<T> &v) {
    if (!v.empty()) {
        cout << v[0];
    }
    for (int i = 1; i < (int) v.size(); ++i) {
        cout << " " << v[i];
    }
    cout << endl;
}

template <class T>
inline void read_vector(vector<T> &v, int n, int start = 0) {
    for (int i = start; i < start + n; ++i) {
        cin >> v[i];
    }
}

#define MAX_PRIME 3200
const ll MOD = 1e9 + 7;

ll mypow(ll b, ll e, ll mod) {
    if (e == 0) {
        return 1;
    }

    ll ret = 1;
    while (e) {
        if (e & 1) {
            ret = (ret * b) % mod;
        }
        e >>= 1;
        b = (b * b) % mod;
    }
    return ret;
}

ll inv_mod(ll num, ll den, ll mod) {
    ll b = mod, x = 0, lastx = 1, aux;
    while (b) {
        ll q = den / b, r = den % b;
        den = b; b = r;
        aux = x;
        x = lastx - q * x, lastx = aux;
    }
    while (lastx < 0) {
        lastx += mod;
    }
    return (num * lastx) % mod;
}

ll neg_mod(ll n, ll mod) {
    if (n < 0) {
        return n + mod;
    }
    return n % mod;
}

ll sum_gp(ll first, ll rate, ll len, ll mod) {
    ll num = first - (first * mypow(rate, len, mod)) % mod;
    num = neg_mod(num, mod);
    ll den = neg_mod(1 - rate, mod);
    return inv_mod(num, den, mod);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> primes;
    bitset<MAX_PRIME> is_prime;
    is_prime.set();
    for (int i = 2; i <= MAX_PRIME; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= MAX_PRIME; j += i) {
                is_prime[j] = 0;
            }
            primes.pb(i);
        }
    }

    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;

        vector<pair<int, int>> factors;
        for (int i = 0; i < (int) primes.size() && n != 1; ++i) {
            if (n % primes[i] == 0) {
                int cnt_factor = 0;
                while (n % primes[i] == 0) {
                    cnt_factor++;
                    n /= primes[i];
                }
                factors.pb(mp(primes[i], cnt_factor));
            }
        }
        if (n != 1) {
            factors.pb(mp(n, 1));
        }

        ll sum = 1;
        for (int i = 0; i < (int) factors.size(); ++i) {
            ll first = mypow(factors[i].fi, factors[i].se, MOD);

            // Through Fermat's little theorem: if mod is prime then for any integer n, (n ** e) % mod = (n ** (e % (mod - 1))) % mod
            ll len = (factors[i].se * mypow(2LL, k, MOD - 1)) % (MOD - 1);
            len = neg_mod(len - factors[i].se + 1, MOD - 1);

            ll sum_factor = sum_gp(first, factors[i].fi, len, MOD);
            sum = (sum * sum_factor) % MOD;
        }
        cout << sum << endl;
    }

    return 0;
}
