typedef long long ll;

/*
 * Through Fermat's little theorem: if mod is prime then for any integer n, (n ** e) % mod = (n ** (e % (mod - 1))) % mod
 */

// (num / den) % mod
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

// (a * b) % mod taking into account that a * b might overflow
ll mul_mod(ll a, ll b, ll mod){
    ll x = 0, y = a % mod;
    while (b > 0) {
        if (b % 2 == 1) {
            x = (x + y) % mod;
        }
        y = (y * 2) % mod;
        b /= 2;
    }
    return x % mod;
}

// ALERT: (__int128) IS PLATFORM DEPENDENT
ll mul_mod_faster(ll a, ll b, ll mod) {
  return (__int128) a * b % mod;
}

ll neg_mod(ll n, ll mod) {
    if (n < 0) {
        return n + mod;
    }
    return n;
}
