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

#define MAX 55

char s[MAX], out[MAX];

int main() {
    scanf("%s", s);
    int n = strlen(s);

    int mid = n / 2 - (n % 2 == 0);
    int j = 1;
    out[0] = s[mid];
    for (int i = 1; i <= n / 2; ++i) {
        if (mid + i < n) {
            out[j] = s[mid + i];
        }
        if (mid - i >= 0) {
            out[j + 1] = s[mid - i];
        }
        j += 2;
    }

    printf("%s\n", out);

    return 0;
}
