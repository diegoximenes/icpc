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
