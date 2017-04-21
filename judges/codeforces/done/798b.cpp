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

#define MAX 55

string v[MAX];

string slide(string s) {
    string ret = "";
    int n = s.size();
    for (int i = 1; i <= n; i++)
        ret.pb(s[i % n]);
    return ret;
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> v[i];

    int sol = INF;
    int len = v[0].size();
    for (int i = 0; i < len; ++i) {
        int lsol = i;
        if (i > 0) v[0] = slide(v[0]);

        for (int j = 1; j < n; ++j) {
            if (v[j] == v[0]) continue;

            string s = v[j];
            bool can = 0;
            for (int k = 1; k <= len; ++k) {
                s = slide(s);
                if (s == v[0]) {
                    lsol += k;
                    can = 1;
                    break;
                }
            }
            if (!can) {
                lsol = INF;
                break;
            }
        }

        sol = min(lsol, sol);
    }

    printf("%d\n", (sol < INF) ? sol : -1);

    return 0;
}
