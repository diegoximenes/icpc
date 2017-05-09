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

bool in_pos(int a, int s) {
    int i = (s / 50) % 475;
    for (int j = 0; j < 25; ++j) {
        i = (i * 96 + 42) % 475;
        if (26 + i == a) return 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);

    int p, x, y;
    cin >> p >> x >> y;

    int upper = 5000;
    for (int i = 0; i <= upper; ++i) {
        for (int j = 0; j <= upper; ++j) {
            int a = x + 100 * i - 50 * j;
            if (a < y) break;
            // cout << "i=" << i << ", j=" << j << endl;
            if (in_pos(p, a)) {
                cout << i << endl;
                return 0;
            }
        }
    }

    return 0;
}
