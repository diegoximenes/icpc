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

double dist(double x1, double y1, double x2, double y2) {
   return hypot(fabs(x1 - x2), fabs(y1 - y2));
}

int main() {
    double a, b, c, x1, y1, x2, y2;
    scanf("%lf %lf %lf %lf %lf %lf %lf", &a, &b, &c, &x1, &y1, &x2, &y2);

    double sol = 1.0 / 0.0;
    double sol1 = fabs(x1 - x2) + fabs(y1 - y2);
    if (!cmp_double(a, 0) || !cmp_double(b, 0)) {
        sol = sol1;
    } else {
        double y_intersect_1 = (- c - a * x1) / b;
        double x_intersect_1 = (- c - b * y1) / a;
        double y_intersect_2 = (- c - a * x2) / b;
        double x_intersect_2 = (- c - b * y2) / a;

        double sol2 = fabs(y1 - y_intersect_1) + dist(x1, y_intersect_1, x2, y_intersect_2) + fabs(y2 - y_intersect_2);
        double sol3 = fabs(y1 - y_intersect_1) + dist(x1, y_intersect_1, x_intersect_2, y2) + fabs(x2 - x_intersect_2);
        double sol4 = fabs(x1 - x_intersect_1) + dist(x_intersect_1, y1, x2, y_intersect_2) + fabs(y2 - y_intersect_2);
        double sol5 = fabs(x1 - x_intersect_1) + dist(x_intersect_1, y1, x_intersect_2, y2) + fabs(x2 - x_intersect_2);

        sol = min(sol, sol1);
        sol = min(sol, sol2);
        sol = min(sol, sol3);
        sol = min(sol, sol4);
        sol = min(sol, sol5);
    }

    printf("%.8lf\n", sol);

    return 0;
}
