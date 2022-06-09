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

int main() {
    fast_io;
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<pair<int, int>> mod;
        vector<int> mod0;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;

            if (a % k == 0) {
                mod0.pb(a);
            } else {
                mod.pb(mp(a % k, a));
            }
        }

        ll sum = 0;
        for (int i = 0; i < (int) mod0.size(); ++i) {
            sum += mod0[i] / k;
        }
        if (mod0.size() & 1) {
            sum -= mod0[0] / k;
            mod.pb(mp(0, mod0[0]));
        }

        sort(mod.begin(), mod.end());
        int l = 0, r = mod.size() - 1;
        while (l < r) {
            if (mod[l].fi + mod[r].fi < k) {
                sum += (mod[l].se + mod[l + 1].se) / k;
                l += 2;
            } else {
                sum += (mod[l].se + mod[r].se) / k;
                l += 1;
                r -= 1;
            }
        }

        cout << sum << endl;
    }

    return 0;
}
