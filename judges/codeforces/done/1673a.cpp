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
int sum[MAX];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s);
        int n = strlen(s);

        sum[0] = 0;
        for (int i = 1; i <= n; ++i) {
            sum[i] = s[i - 1] - 'a' + 1 + sum[i - 1];
        }

        int alice = 0, bob = 0;
        if (n & 1) {
            if (s[0] > s[n - 1]) {
                alice = sum[n - 1];
                bob = s[n - 1] - 'a' + 1;
            } else {
                alice = sum[n] - (s[0] - 'a' + 1);
                bob = s[0] - 'a' + 1;
            }
        } else {
            alice = sum[n];
        }

        if (alice > bob) {
            printf("Alice %d\n", alice - bob);
        } else {
            printf("Bob %d\n", bob - alice);
        }
    }

    return 0;
}
