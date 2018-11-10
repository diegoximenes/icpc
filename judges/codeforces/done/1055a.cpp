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

#define MAX 1005

int a[MAX], b[MAX];

int main() {
    int n, s;
    scanf("%d %d", &n, &s);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
    }

    s--;
    if (a[0] == 0) {
        puts("NO");
        return 0;
    }
    if(a[s] == 1) {
        puts("YES");
        return 0;
    }
    if (b[s] == 0) {
        puts("NO");
        return 0;
    }

    for (int i = s + 1; i < n; ++i) {
        if (a[i] && b[i]) {
            puts("YES");
            return 0;
        }
    }

    puts("NO");

    return 0;
}
