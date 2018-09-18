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

#define MAX 20

int p_min[MAX], p_max[MAX];

void print_v(int *v, int n) {
    printf("%d", v[0]);
    for (int i = 1; i < n; ++i) {
        printf(" %d", v[i]);
    }
    puts("");
}

int main() {
    int n;
    scanf("%d", &n);

    p_min[0] = n;
    for (int i = 1; i < n; ++i) {
        p_min[i] = i;
    }

    int mid = n / 2 - (n % 2 == 0);
    p_max[mid] = 1;
    for (int i = 0; i < mid; ++i) {
        p_max[i] = i + 2;
    }
    if (n > 1) {
        p_max[n - 1] = mid + 2;
        for (int i = mid + 1, k = 1; i < n - 1; ++i, ++k) {
            p_max[i] = mid + 2 + k;
        }
    }

    print_v(p_max, n);
    print_v(p_min, n);

    return 0;
}
