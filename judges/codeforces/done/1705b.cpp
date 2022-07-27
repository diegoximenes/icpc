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

#define MAX 200000

ll a[MAX];

int main() {
    fast_io;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        set<int> zero_pos;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            if (!a[i] && (i < n - 1)) {
                zero_pos.insert(i);
            }
        }

        ll out = 0;
        int i = 0;
        while (i < n - 1) {
            if (!a[i]) {
                zero_pos.erase(i);
                i++;
                continue;
            }

            if (zero_pos.empty()) {
                for (int j = i; j < n - 1; ++j) {
                    out += a[j];
                }
                break;
            } else {
                int j = *zero_pos.begin();
                zero_pos.erase(zero_pos.begin());
                a[j]++;
                a[i]--;
                out++;
            }
        }

        cout << out << endl;
    }

    return 0;
}
