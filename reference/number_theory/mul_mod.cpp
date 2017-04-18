// (a * b) % c taking into account that a * b might overflow
ll mul_mod(ll a, ll b, ll c){
    ll x = 0, y = a % c;
    while (b > 0) {
        if (b % 2 == 1) x = (x + y) % c;
        y = (y * 2) % c;
        b /= 2;
    }
    return x % c;
}

// FASTER VERSION
// ALERT: (__int128) IS PLATFORM DEPENDENT
ll mul_mod(ll a, ll b, ll c) {
  return (__int128) a * b % c;
}
