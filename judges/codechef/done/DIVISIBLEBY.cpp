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

#define MAX 500000
#define MAX_PRIME 708

int a[MAX];
map<int, int> factors[MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> primes;
    bitset<MAX_PRIME + 1> is_prime;
    is_prime.set();
    for (int i = 2; i <= MAX_PRIME; ++i) {
        if (is_prime[i]) {
            primes.pb(i);
            for (int j = i * i; j <= MAX_PRIME; j += i) {
                is_prime[j] = 0;
            }
        }
    }

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        read_array(a, n);
        for (int i = 0; i < n; ++i) {
            factors[i].clear();
        }

        unordered_set<int> found_primes;
        for (int i = 0; i < n; ++i) {
            int x = a[i];
            for (auto p: primes) {
                int exp = 0;
                while (x % p == 0) {
                    exp++;
                    x /= p;
                }
                if (exp) {
                    factors[i][p] =  exp;
                    found_primes.insert(p);
                }
            }
            if (x != 1) {
                factors[i][x] = 1;
                found_primes.insert(x);
            }
        }

        unordered_map<int, int> min_exp;
        for (auto p: found_primes) {
            for (int i = 0; i < n; ++i) {
                if (min_exp.find(p) == min_exp.end()) {
                    min_exp[p] = factors[i][p];
                } else {
                    min_exp[p] = min(min_exp[p], factors[i][p]);
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            ll ans = 1;
            for (auto f: factors[i]) {
                int mul_times = f.se - min_exp[f.fi];
                for (int j = 0; j < mul_times; ++j) {
                    ans *= (ll) f.fi;
                }
            }

            if (i > 0) {
                cout << ' ';
            }
            cout << ans;
        }
        cout << endl;
    }

    return 0;
}
