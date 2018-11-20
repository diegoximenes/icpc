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

#define MAX 105

int cnt[MAX];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    memset(cnt, 0, sizeof(cnt));
    int cnt_dishes = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        cnt[x]++;

        cnt_dishes = max(cnt_dishes, cnt[x] / k + (cnt[x] % k != 0));
    }

    int sol = 0;
    for (int i = 0; i < MAX; ++i) {
        if (cnt[i]) {
            sol += cnt_dishes * k - cnt[i];
        }
    }
    printf("%d\n", sol);

    return 0;
}
