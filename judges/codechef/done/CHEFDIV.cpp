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

#define MAX 1000005
#define MAX2 100005

vector<ll> primes;
bitset<MAX> is_prime;

void sieve(ll n) {
    is_prime.set();
    is_prime[0] = is_prime[1] = 1;
    for (ll i = 2; i <= n; ++i) {
        if (is_prime[i]) {
            primes.pb(i);
            for (ll j = i * i; j <= n; j += i) is_prime[j] = 0;
        }
    }
}

multiset<int> powers[MAX2];
ll num[MAX2];

int main() {
    ios::sync_with_stdio(false);

    ll a, b;
    cin >> a >> b;

    sieve(MAX - 1);

    for (ll i = a; i <= b; ++i) num[i - a] = i;

    for (int i = 0; i < (int) primes.size(); ++i) {
        ll l = a / primes[i];
        if (primes[i] * l < a) l++;
        for (ll j = primes[i] * l; j <= b; j += primes[i]) {
            int cnt = 0;
            while (num[j - a] % primes[i] == 0) {
                num[j - a] /= primes[i];
                cnt++;
            }
            powers[j - a].insert(-cnt);
        }
    }
    for (ll i = a; i <= b; ++i)
        if (num[i - a] != 1)
            powers[i - a].insert(-1);

    ll sol = 0;
    for (ll i = a; i <= b; ++i) {
        multiset<int>::iterator it;
        ll prod = 1;
        for (it = powers[i - a].begin(); it != powers[i - a].end(); ++it)
            prod *= (-*it + 1);
        sol += prod - 1;
        while (!powers[i - a].empty()) {
            ll x = -*powers[i - a].begin();
            powers[i - a].erase(powers[i - a].begin());
            if (x - 1 > 0) powers[i - a].insert(-(x - 1));
            prod /= (x + 1);
            prod *= (x - 1 + 1);
            sol += prod;
        }
    }
    cout << sol << endl;

    return 0;
}
