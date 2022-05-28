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

#define MAX 101

int a[MAX], b[MAX];

void mysort(int n, int *v1, int *v2, vector< pair<int, int> > &out) {
    for (int i = 0; i < n; ++i) {
        int min_v = v1[i], min_id = i;
        for (int j = i + 1; j < n; ++j) {
            if (v1[j] < min_v) {
                min_v = v1[j];
                min_id = j;
            }
        }
        if (min_id != i) {
            out.pb(mp(i, min_id));
            swap(v1[i], v1[min_id]);
            swap(v2[i], v2[min_id]);
        }
    }

}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i < n; ++i) {
            scanf("%d", &b[i]);
        }

        vector< pair<int, int> > out;
        mysort(n, a, b, out);
        mysort(n, b, a, out);

        bool can = 1;
        for (int i = 1; i < n; ++i) {
            if (a[i] < a[i - 1]) {
                can = 0;
            }
        }
        if (!can) {
            printf("-1\n");
        } else {
            printf("%d\n", (int) out.size());
            for (int i = 0; i < (int) out.size(); ++i) {
                printf("%d %d\n", out[i].fi + 1, out[i].se + 1);
            }
        }
    }

    return 0;
}
