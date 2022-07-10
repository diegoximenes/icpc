#include <bits/stdc++.h>
#include <cmath>
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

/*
 *
 * 1000000 - NOT
 *
 * 0000001 - OK
 *
 * 1111110 - OK
 *
 * 0111111 - NOT
 *
 * 010110
 *
 */

int main() {
    fast_io;
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        ll out = 1;
        ll last0 = -1, last1 = -1;

        if (s[0] == '0') {
            last0 = 0;
        } else {
            last1 = 0;
        }

        for (int i = 1; i < n; ++i) {
            out += 1;
            if (s[i] != s[i - 1]) {
                if (s[i] == '1') {
                    if (last0 > -1) {
                        out += last0 + 1;
                    }
                } else {
                    if (last1 > -1) {
                        out += last1 + 1;
                    }
                }
            }
            if (s[i] == '1') {
                last1 = i;
            } else {
                last0 = i;
            }
        }

        cout << out << endl;
    }

    return 0;
}
