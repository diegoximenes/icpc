/*
Deterministic for n < 341,550,071,728,321
*/

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

ll mul_mod(ll a, ll b, ll c){
    ll x = 0, y = a % c;
    while (b > 0) {
        if (b % 2 == 1) x = (x + y) % c;
        y = (y * 2) % c;
        b /= 2;
    }
    return x % c;
}

ll pow_mod(ll a, ll n, ll mod) {
    ll power = a;
    ll result = 1;
    while (n) {
        if (n & 1) result = mul_mod(result, power, mod);
        power = mul_mod(power, power, mod);
        n >>= 1;
    }
    return result;
}

bool witness(ll n, ll s, ll d, ll a) {
    ll x = pow_mod(a, d, n);
    ll y;

    while (s) {
        y = mul_mod(x, x, n);
        if (y == 1 && x != 1 && x != n - 1) return false;
        x = y;
        --s;
    }
    if (y != 1) return false;
    return true;
}

bool is_prime(ll n) {
    if (((!(n & 1)) && n != 2 ) || (n < 2) || (n % 3 == 0 && n != 3))
        return false;
    if (n <= 3) return true;

    ll d = n / 2;
    ll s = 1;
    while (!(d & 1)) {
        d /= 2;
        ++s;
    }

    if (n < 1373653LL)
        return witness(n, s, d, 2) && witness(n, s, d, 3);
    if (n < 9080191LL)
        return witness(n, s, d, 31) && witness(n, s, d, 73);
    if (n < 4759123141LL)
        return (witness(n, s, d, 2) && witness(n, s, d, 7) &&
                witness(n, s, d, 61));
    if (n < 1122004669633LL)
        return (witness(n, s, d, 2) && witness(n, s, d, 13) &&
                witness(n, s, d, 23) && witness(n, s, d, 1662803));
    if (n < 2152302898747LL)
        return (witness(n, s, d, 2) && witness(n, s, d, 3) &&
                witness(n, s, d, 5) && witness(n, s, d, 7) &&
                witness(n, s, d, 11));
    if (n < 3474749660383LL)
        return (witness(n, s, d, 2) && witness(n, s, d, 3) &&
                witness(n, s, d, 5) && witness(n, s, d, 7) &&
                witness(n, s, d, 11) && witness(n, s, d, 13));
    return (witness(n, s, d, 2) && witness(n, s, d, 3) &&
            witness(n, s, d, 5) && witness(n, s, d, 7) &&
            witness(n, s, d, 11) && witness(n, s, d, 13) &&
            witness(n, s, d, 17));
}
