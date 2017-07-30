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

int main() {
    char s, e;
    int n;
    scanf("%c %c %d", &s, &e, &n);

    map<char, int> cw;
    cw['^'] = 0;
    cw['>'] = 1;
    cw['v'] = 2;
    cw['<'] = 3;
    map<int, char> ccw;
    ccw['^'] = 0;
    ccw['<'] = 1;
    ccw['v'] = 2;
    ccw['>'] = 3;

    n %= 4;
    bool can_cw = 0, can_ccw = 0;
    if ((cw[s] + n) % 4 == cw[e]) can_cw = 1;
    if ((ccw[s] + n) % 4 == ccw[e]) can_ccw = 1;

    if (can_cw && can_ccw) {
        puts("undefined");
    } else if(can_cw) {
        puts("cw");
    } else {
        puts("ccw");
    }

    return 0;
}
