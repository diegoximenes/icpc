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

#define MAX 200001
#define MAX2 41

string s;
ll len[MAX2];
pair<ll, ll> interval[MAX2];

char solve(int i, ll k) {
    // cout << "i=" << i << ", k=" << k << endl;
    if (i == 0) {
        // cout << "i=0" << endl;
        return s[k - 1];
    }
    if (k <= len[i - 1]) {
        // cout << "k <= len[i - 1]" << ", len[i -1]=" << len[i - 1] << endl;
        return solve(i - 1, k);
    }
    // cout << "interval[i].fi + k - len[i - 1] - 1=" << interval[i].fi + k - len[i - 1] - 1<< endl;
    return solve(i - 1, interval[i].fi + k - len[i - 1] - 1);
}

int main() {
    fast_io;
    int t;
    cin >> t;
    while (t--) {
        int n, c, q;
        cin >> n >> c >> q >> s;

        len[0] = n;
        for (int i = 1; i <= c; ++i) {
            cin >> interval[i].fi >> interval[i].se;
            len[i] = len[i - 1] + interval[i].se - interval[i].fi + 1;
            // cout << "i=" << i << ", len[i]=" << len[i] << endl;
        }

        while (q--) {
            ll k;
            cin >> k;
            cout << solve(c, k) << endl;
        }
    }

    return 0;
}
