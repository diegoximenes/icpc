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

#define MAX 100005

int n, v[MAX];

int main() {
    int t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; ++tc) {
        map<int, int> cnt[2];

        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &v[i]);
            cnt[i & 1][v[i]]++;
        }

        bool sorted = 1;
        int pos;
        sort(v, v + n);
        for (int i = 0; i < n; ++i) {
            if (cnt[i & 1][v[i]]) {
                cnt[i & 1][v[i]]--;
            } else {
                sorted = 0;
                pos = i;
                break;
            }
        }

        printf("Case #%d: ", tc);
        if (sorted) {
            puts("OK");
        } else {
            printf("%d\n", pos);
        }
    }

    return 0;
}
