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

#define MAX 5000

char a[MAX], b[MAX];

bool ethan() {
    int n = strlen(a);
    int m = strlen(b);
    int i = 0, j = 0;
    while (1) {
        if (i == n) {
            return true;
        }
        if (j == m) {
            return false;
        }
        if (a[i] == b[j]) {
            i += 1;
            j += 1;
        } else if (i == 0) {
            j += 1;
        } else {
            i = 0;
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; ++tc) {
        printf("Case #%d: ", tc);

        scanf("%s", a);
        int n = strlen(a);
        bool solved = 0;
        for (int i = 1; i < n; ++i) {
            memset(b, 0, sizeof(b));
            for (int j = 0; j < i; ++j) {
                b[j] = a[j];
            }
            for (int j = i, k = 0; k < n; ++k, ++j) {
                b[j] = a[k];
            }
            if (!ethan()) {
                printf("%s\n", b);
                solved = 1;
                break;
            }
        }
        if (!solved) {
            printf("Impossible\n");
        }
    }

    return 0;
}
