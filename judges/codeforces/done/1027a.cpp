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

char s[MAX];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d %s", &n, s);

        bool can = 1;
        int l = 0, r = n - 1;
        while (l <= r) {
            if (s[l] != s[r] && abs(s[l] - s[r]) != 2) {
                can = 0;
            }
            l++;
            r--;
        }

        puts(can ? "YES" : "NO");
    }
    return 0;
}
