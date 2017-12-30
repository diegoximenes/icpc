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

#define MAX 10005

int n;
double r;
double x[MAX], y[MAX];

bool intersect(double x1, double x2) {
    if (cmp_double(x1, x2) == 0) return 1;
    if (cmp_double(x1 + r, x2 - r) == 0 || cmp_double(x1 - r, x2 + r) == 0) return 1;
    bool ret1 = (cmp_double(x2 + r, x1 + r) < 0 && cmp_double(x2 + r, x1 - r) > 0);
    bool ret2 = (cmp_double(x2 - r, x1 + r) < 0 && cmp_double(x2 - r, x1 - r) > 0);
    // printf("x1=%lf, x2=%lf, ret1=%d, ret2=%d\n", x1, x2, ret1, ret2);
    return (ret1 || ret2);
}

double intersect_pos(double x1, double y1, double x2) {
    if (cmp_double(x1, x2) == 0) return (y1 + 2 * r);
    if (cmp_double(x1 + r, x2 - r) == 0 || cmp_double(x1 - r, x2 + r) == 0) return y1;
    double a = 1;
    double b = - 2.0 * y1;
    double c = y1 * y1 + (x2 - x1) * (x2 - x1) - (2 * r) * (2 * r);
    // printf("a=%lf, b=%lf, c=%lf\n", a, b, c);
    return (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
}

int main() {
    scanf("%d %lf", &n, &r);
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &x[i]);
    }

    y[0] = r;
    printf("%.8lf", y[0]);
    for (int i = 1; i < n; ++i) {
        y[i] = r;
        for (int j = 0; j < i; ++j) {
            // printf("i=%d, j=%d, intersect=%d, intersect_pos=%lf\n", i, j, intersect(x[j], x[i]),intersect_pos(x[j], y[j], x[i]));
            if (intersect(x[i], x[j])) {
                y[i] = max(y[i], intersect_pos(x[j], y[j], x[i]));
            }
        }
        printf(" %.8lf", y[i]);
    }
    puts("");

    return 0;
}
