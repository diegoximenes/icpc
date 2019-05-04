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

#define MAX 100005

int first[MAX], last[MAX];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= k; ++i) {
        int x;
        scanf("%d", &x);
        if (!first[x]) {
            first[x] = i;
        }
        last[x] = i;
    }

    int sol = 0;
    for (int i = 1; i <= n; ++i) {
        if (i - 1 >= 1) {
            if (!first[i] || !first[i - 1] || last[i] < first[i - 1]) {
                // printf("%d,%d\n", i - 1, i);
                sol++;
            }
        }
        if (i + 1 <= n) {
            if (!first[i] || !first[i + 1] || last[i] < first[i + 1]) {
                // printf("%d,%d\n", i + 1, i);
                sol++;
            }
        }
        if (!first[i]) {
            // printf("%d,%d\n", i, i);
            sol++;
        }
    }
    printf("%d\n", sol);

    return 0;
}
