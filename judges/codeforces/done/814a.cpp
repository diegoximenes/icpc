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

#define MAX 105

int n, k;
int a[MAX], b[MAX];

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < k; ++i) scanf("%d", &b[i]);

    sort(b, b + k);
    int j = k - 1;
    for (int i = 0; i < n; ++i)
        if (a[i] == 0)
            a[i] = b[j--];

    bool is_increasing = 1;
    for (int i = 1; i < n; ++i)
        if (a[i] <= a[i - 1])
            is_increasing = 0;

    puts(is_increasing ? "No" : "Yes");

    return 0;
}
