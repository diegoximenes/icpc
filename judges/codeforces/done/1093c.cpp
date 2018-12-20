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

ll sol[MAX];

int main() {
    int n;
    cin >> n;

    ll last_left = 0;
    ll last_right = 1000000000000000000;
    for (int i = 0; i < n / 2; ++i) {
        ll sum;
        cin >> sum;

        if (sum - last_left <= last_right) {
            last_right = sum - last_left;
            sol[i] = last_left;
            sol[n - i - 1] = last_right;
        } else {
            last_left = sum - last_right;
            sol[i] = last_left;
            sol[n - i - 1] = last_right;
        }
    }

    cout << sol[0];
    for (int i = 1; i < n; ++i) {
        cout << " " << sol[i];
    }
    cout << endl;

    return 0;
}
