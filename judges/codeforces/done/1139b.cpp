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

int v[MAX];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    int curr_max = INF;
    ll sol = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (v[i] < curr_max) {
            curr_max = v[i];
        } else {
            curr_max--;
        }
        if (!curr_max) {
            break;
        }
        sol += curr_max;
    }
    cout << sol << endl;

    return 0;
}
