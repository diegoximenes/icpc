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

#define MAX 55

string a[MAX];
int out[MAX];

int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        ll n, k, v;
        cin >> n >> k >> v;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        for (int i = k * (v - 1) % n, j = 0; j < k; ++i, ++j) {
            out[j] = i % n;
        }
        sort(out, out + k);

        cout << "Case #" << tc << ":";
        for (int i = 0; i < k; ++i) {
            cout << " " << a[out[i]];
        }
        cout << endl;
    }

    return 0;
}
