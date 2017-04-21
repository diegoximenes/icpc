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

#define MAX 100005

int a[MAX];

int gcd(int a, int b) {
    return (b == 0 ? a : gcd(b, a % b));
}

int match_odd(int cnt_odd) {
    return cnt_odd / 2 + 2 * (cnt_odd % 2);
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    int g = a[0];
    for (int i = 1; i < n; ++i) g = gcd(g, a[i]);

    puts("YES");

    if (g > 1) {
        puts("0");
        return 0;
    }

    int sol = 0;
    int cnt_odd = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == 0) {
            sol += match_odd(cnt_odd);
            cnt_odd = 0;
        } else {
            cnt_odd++;
        }
    }
    sol += match_odd(cnt_odd);

    printf("%d\n", sol);

    return 0;
}
