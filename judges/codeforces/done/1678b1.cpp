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

char s[MAX];

char invert(char c) {
    if (c == '0') {
        return '1';
    }
    return '0';
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d %s", &n, s);

        int l = 0;
        int min_op = 0;
        for (int i = 1; i < n; ++i) {
            if (s[i] != s[i - 1]) {
                if ((i - l) & 1) {
                    if (i - l == 1) {
                        s[l] = invert(s[l]);
                    } else {
                        s[i] = invert(s[i]);
                    }
                    min_op++;
                } else {
                    l = i;
                }
            }
        }

        printf("%d\n", min_op);
    }

    return 0;
}
