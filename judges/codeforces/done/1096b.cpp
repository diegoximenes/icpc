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

#define MAX 200005
#define MOD 998244353LL

ll n;
char s[MAX];

int main() {
    fast_io;
    cin >> n >> s;

    ll cnt_left = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == s[0]) {
            cnt_left++;
        } else {
            break;
        }
    }

    ll cnt_right = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == s[n - 1]) {
            cnt_right++;
        } else {
            break;
        }
    }

    ll sol = 0;
    if (s[0] != s[n - 1]) {
        sol = 1;
        sol = (sol + cnt_left) % MOD;
        sol = (sol + cnt_right) % MOD;
    } else {
        sol = (sol + ((cnt_left + 1) * (cnt_right + 1)) % MOD) % MOD;
    }

    cout << sol << endl;

    return 0;
}
