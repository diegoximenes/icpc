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

#define MAX 31624

bitset<MAX> is_prime;
vector<ll> primes;

void sieve(int n) {
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.pb(i);
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = 0;
            }
        }
    }
}

int main() {
    sieve(MAX - 1);

    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;

        int cnt_divs = 0;
        int divs[3];
        for (int i = 0; (cnt_divs < 3) && (i < (int) primes.size()); ++i) {
            if (n % primes[i] == 0) {
                n /= primes[i];
                divs[cnt_divs++] = primes[i];
            }
            if (cnt_divs < 3) {
                if (n % (primes[i] * primes[i]) == 0) {
                    n /= primes[i] * primes[i];
                    divs[cnt_divs++] = primes[i] * primes[i];
                }
            }
            if (cnt_divs < 3) {
                if (n % (primes[i] * primes[i] * primes[i]) == 0) {
                    n /= primes[i] * primes[i] * primes[i];
                    divs[cnt_divs++] = primes[i] * primes[i] * primes[i];
                }
            }
        }

        if (cnt_divs != 3) {
            printf("NO\n");
        } else {
            printf("YES\n%d %d %d\n", divs[0], divs[1], divs[2]);
        }
    }

    return 0;
}
