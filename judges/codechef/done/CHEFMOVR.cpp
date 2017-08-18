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

#define MAX 100005

ll v[MAX];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        ll sum = 0;
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
            sum += v[i];
        }

        ll sol = 0;
        bool can = 1;
        if (sum % n != 0) can = 0;
        ll target = sum / n;

        for (int i = 0; i < n - d; ++i) {
            sol += abs(v[i] - target);
            v[i + d] += v[i] - target;
            v[i] = target;
        }

        for (int i = 0; i < n; ++i)
            if (v[i] != target)
                can = 0;

        if (!can) sol = -1;
        cout << sol << endl;
    }

    return 0;
}
