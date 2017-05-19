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

#define MAX 35

double k, v[MAX], sum_right[MAX], sum_left[MAX];
int n;

int solve_right(int i, double sum) {
    if (cmp_double(sum, k) == 1) return 0;
    if (i == n + 1) return 1;
    if (cmp_double(sum_right[i] + sum, k) <= 0) return (1 << (n - i + 1));
    return solve_right(i + 1, sum) + solve_right(i + 1, sum + v[i]);
}

int solve_left(int i, double sum) {
    if (cmp_double(sum, k) == 1) return 0;
    if (i == 0) return 1;
    if (cmp_double(sum_left[i] + sum, k) <= 0) return (1 << (i));
    return solve_left(i - 1, sum) + solve_left(i - 1, sum + v[i]);
}

int main() {
    ios::sync_with_stdio(false);

    scanf("%d %lf", &n, &k);
    k = log(k);
    for (int i = 1; i <= n; ++i) {
        scanf("%lf", &v[i]);
        v[i] = log(v[i]);
    }

    sort(v, v + n);

    int i_right = -1;
    sum_right[n + 1] = 0;
    for (int i = n; i >= 0; --i) {
        sum_right[i] = v[i] + sum_right[i + 1];
        if (cmp_double(sum_right[i], k) <= 0) i_right = i;
    }
    int i_left = -1;
    sum_left[0] = 0;
    for (int i = 1; i <= n; ++i) {
        sum_left[i] = v[i] + sum_left[i - 1];
        if (cmp_double(sum_left[i], k) <= 0) i_left = i;
    }

    int sol;
    if (i_left == -1 && i_right == -1) {
        sol = 1;
    } else if (i_left != -1 && i_right == -1) {
        sol = solve_left(n, 0);
    } else if (i_left == -1 && i_right != -1) {
        sol = solve_right(1, 0);
    } else if (i_right < n - i_left) {
        sol = solve_right(1, 0);
    } else {
        sol = solve_left(n, 0);
    }

    printf("%d\n", sol - 1);

    return 0;
}
