#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast_io ios::sync_with_stdio(false)
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

#define MAXMASK (1 << 19)

vector<int> va, vb;
int dp[MAXMASK][2];
int na, nb;

vector<int> get_digits(ll x) {
    vector<int> ret;
    while (x != 0LL) {
        ret.pb(x % 10LL);
        x /= 10LL;
    }
    return ret;
}

int opt(int mask, int a_is_lower, int len) {
    if (mask == (1 << na) - 1) {
        return 1;
    }
    int &ret = dp[mask][a_is_lower];
    if (ret != -1) return ret;

    ret = 0;
    for (int i = 0; i < na; ++i) {
        if (va[i] == 0 && mask == 0) continue;
        if ((mask & (1 << i)) == 0) {
            if (!a_is_lower && va[i] > vb[len]) continue;
            ret = opt(mask | (1 << i), a_is_lower || (va[i] < vb[len]), len + 1);
            if (ret) break;
        }
    }
    // printf("mask=%d, a_is_lower=%d, ret=%d\n", mask, a_is_lower, ret);
    return ret;
}

void reconstruct(int mask, int a_is_lower, int len) {
    if (mask == (1 << na) - 1) {
        return;
    }
    for (int i = 0; i < na; ++i) {
        if (va[i] == 0 && mask == 0) continue;
        if ((mask & (1 << i)) == 0) {
            if (!a_is_lower && va[i] > vb[len]) continue;
            if (opt(mask, a_is_lower, len) == opt(mask | (1 << i), a_is_lower || (va[i] < vb[len]), len + 1)) {
                cout << va[i];
                reconstruct(mask | (1 << i), a_is_lower || (va[i] < vb[len]), len + 1);
                return;
            }
        }
    }
}

int main() {
    ll a, b;
    cin >> a >> b;
    va = get_digits(a);
    vb = get_digits(b);
    na = va.size();
    nb = vb.size();

    sort(va.begin(), va.end());
    reverse(va.begin(), va.end());
    reverse(vb.begin(), vb.end());

    memset(dp, -1, sizeof(dp));
    opt(0, (na < nb), 0);
    reconstruct(0, (na < nb), 0);
    cout << endl;

    return 0;
}
