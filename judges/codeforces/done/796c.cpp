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

#define MAX 300005

int a[MAX];
vector<int> g[MAX];

int main() {
    int n;
    scanf("%d", &n);

    multiset<int> heap;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        heap.insert(-a[i]);
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        --u; --v;
        g[u].pb(v);
        g[v].pb(u);
    }

    int sol = INF;
    for (int u = 0; u < n; ++u) {
        int lsol = a[u];
        heap.erase(heap.find(-a[u]));
        for (int i = 0; i < (int) g[u].size(); ++i) {
            int v = g[u][i];
            heap.erase(heap.find(-a[v]));
            lsol = max(lsol, a[v] + 1);
        }

        if (!heap.empty()) lsol = max(lsol, -*heap.begin() + 2);

        heap.insert(-a[u]);
        for (int i = 0; i < (int) g[u].size(); ++i) {
            int v = g[u][i];
            heap.insert(-a[v]);
        }

        sol = min(lsol, sol);
    }

    printf("%d\n", sol);

    return 0;
}
