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

ll gcd(ll a, ll b) {
    return (b == 0 ? a : gcd(b, a % b));
}

ll lcm(ll a, ll b) {
    return a * (b / gcd(a, b));
}

#define MAX 1000001

vector<int> primes;

vector<int> factors(int x) {
    vector<int> f;
    for (int i = 0; x != 1 && i < (int) primes.size();) {
        if (x % primes[i] == 0) {
            f.pb(primes[i]);
            x /= primes[i];
        } else {
            i++;
        }
    }
    return f;
}

void find_divisors(int ip, int curr_div, int x, unordered_set<int> &divisors) {
    // cout << "0: ip=" << ip << ", curr_div=" << curr_div << ", x=" << x << endl;
    if (curr_div > 1) {
        // cout << "div=" << curr_div << endl;
        divisors.insert(curr_div);
    }
    if (ip == (int) primes.size()) {
        return;
    }
    if (primes[ip] > x) {
        return;
    }

    // cout << "1: ip=" << ip << ", curr_div=" << curr_div << ", x=" << x << endl;

    if (x % primes[ip] == 0) {
        find_divisors(ip, curr_div * primes[ip], x / primes[ip], divisors);
    }
    find_divisors(ip + 1, curr_div, x, divisors);
}

int dp[2][MAX];
ll opt(vector<int> &divisors, int k) {
    if (divisors.size() == 0) {
        return 0;
    }

    dp[0][1] = 0;
    for (auto d: divisors) {
        dp[0][d] = dp[1][d] = INF;
    }
    for (int i = 1; i <= (int) divisors.size(); ++i) {
        for (int j = 0; j < (int) divisors.size(); ++j) {
            dp[i & 1][divisors[j]] = dp[(i - 1) & 1][divisors[j]];
            if (divisors[i - 1] <= k && divisors[j] % divisors[i - 1] == 0 && dp[i & 1][divisors[j] / divisors[i - 1]] < INF) {
                dp[i & 1][divisors[j]] = min(dp[i & 1][divisors[j]], 1 + dp[i & 1][divisors[j] / divisors[i - 1]]);
            }
            // cout << "i=" << i << ", j=" << j << ", divisors=" << divisors[j] << ", dp=" << dp[i & 1][divisors[j]] << endl;
        }
    }
    return dp[divisors.size() & 1][divisors.back()];
}

vector<int> from_set_to_vector(unordered_set<int> &s) {
    vector<int> v;
    for (auto x : s) {
        v.pb(x);
    }
    sort(v.begin(), v.end());
    return v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    bitset<MAX> is_prime;
    is_prime.set();
    for (ll i = 2; i < MAX; i++) {
        if (is_prime[i]) {
            primes.pb(i);
            for (ll j = i * i; j < MAX; j += i) {
                is_prime[j] = 0;
            }
        }
    }

    int tc;
    cin >> tc;
    while (tc--) {
        ll x, y, k;
        cin >> x >> y >> k;

        ll l = lcm(x, y);

        // cout << "lcm=" << l << endl;

        unordered_set<int> divisors;
        find_divisors(0, 1, l / x, divisors);
        auto divisors_v = from_set_to_vector(divisors);
        ll cnt_ops = opt(divisors_v, k);
        // cout << "cnt_ops=" << cnt_ops << endl;

        divisors.clear();
        find_divisors(0, 1, l / y, divisors);
        divisors_v = from_set_to_vector(divisors);
        cnt_ops += opt(divisors_v, k);
        // cout << "cnt_ops=" << cnt_ops << endl;

        if (cnt_ops >= INF) {
            cout << -1 << endl;
        } else {
            cout << cnt_ops << endl;
        }
    }

    return 0;
}
