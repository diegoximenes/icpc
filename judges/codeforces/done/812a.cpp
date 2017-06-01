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

int l[5], s[5], r[5], p[5];

int main() {
    for (int i = 1; i <= 4; ++i)
        scanf("%d %d %d %d", &l[i], &s[i], &r[i], &p[i]);

    bool can = 0;

    for (int i = 1; i <= 4; ++i)
        if (p[i] && (l[i] || s[i] || r[i]))
            can = 1;

    if (p[1] && (l[2] || s[3] || r[4])) can = 1;
    if (p[2] && (r[1] || s[4] || l[3])) can = 1;
    if (p[3] && (s[1] || r[2] || l[4])) can = 1;
    if (p[4] && (l[1] || s[2] || r[3])) can = 1;

    puts(can ? "YES" : "NO");

    return 0;
}
