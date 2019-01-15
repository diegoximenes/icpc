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

int main() {
    double n, a, x, y, z, teta;

    scanf("%lf %lf", &n, &a);
    teta = (2 * PI) / n;
    x = 1 + cos(teta);
    y = 2 * a * cos(teta) - 2 * a;
    z = a * a * cos(teta) - a * a;

    double sol1 = (- y + sqrt(y * y - 4 * x * z)) / (2 * x);
    double sol2 = (- y - sqrt(y * y - 4 * x * z)) / (2 * x);
    if (cmp_double(sol1, 0)) {
        printf("%.8lf\n", sol1);
    } else {
        printf("%.8lf\n", sol2);
    }

    return 0;
}
