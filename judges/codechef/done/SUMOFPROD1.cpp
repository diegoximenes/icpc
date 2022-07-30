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
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        vector<int> zero_pos;
        zero_pos.pb(-1);
        for (int i = 0; i < n; ++i) {
            int a;
            scanf("%d", &a);
            if (!a) {
                zero_pos.pb(i);
            }
        }
        zero_pos.pb(n);

        ll out = 0;
        for (int i = 1; i < (int) zero_pos.size(); ++i) {
            ll len = zero_pos[i] - zero_pos[i - 1] - 1;
            out += (1 + len) * len / 2;
        }
        printf("%lld\n", out);
    }

    return 0;
}
