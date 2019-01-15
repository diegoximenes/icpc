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

#define MAX 1000000

vector<ll> primes;
bitset<MAX + 5> is_prime;
ll out[MAX + 5];

void sieve(ll n) {
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;
    for (ll i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            for (ll j = i * i; j <= n; j += i) {
                is_prime[j] = 0;
            }
            primes.pb(i);
        }
    }
}

int main() {
    fast_io;
    sieve(MAX);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;

        int i = 0, p = 2, curr = 2, next = 3;
        while (1) {
            out[i] = curr * primes[p];
            i++;
            if (i == n) {
                break;
            }
            out[i] = next * primes[p];
            i++;
            if (i == n) {
                break;
            }
            p++;
            swap(curr, next);
        }

        if ((n & 1) && (curr == 3)) {
            out[0] *= primes[p];
        } else if ((n & 1) && (curr == 2)) {
            out[0] /= 2;
            out[0] *= primes[p];
        }  else if (!(n & 1) && (curr == 2)) {
            out[0] *= 7;
            out[n - 1] *= 7;
        }

        cout << out[0];
        for (int i = 1; i < n; ++i) {
            cout << " " << out[i];
        }
        cout << endl;
    }

    return 0;
}
