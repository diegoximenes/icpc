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

#define MAX 105

int v[MAX];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d", &v[i]);

        bool can = 1;
        int l = 0, r = n - 1;
        for (int a = 1; a <= 7; ++a) {
            if (v[l] != a || v[r] != a) can = 0;
            while (v[l] == a && v[r] == a && l + 1 < r) {
                l++; r--;
            }
        }
        if (r - l > 1) can = 0;

        puts(can ? "yes" : "no");
    }

    return 0;
}
