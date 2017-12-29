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

int n, m;
vector<int> g[MAX];
int color[MAX], deg[MAX];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &color[i]);
    }
    memset(deg, 0, sizeof(deg));
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[v].pb(u);
        deg[u]++;
    }

    queue<int> q[2];
    for (int i = 0; i < n; ++i) {
        if (deg[i] == 0) {
            q[color[i]].push(i);
        }
    }

    int sol = 0;
    while (!q[0].empty() || !q[1].empty()) {
        for (int c = 0; c <= 1; ++c) {
            if (c == 1 && !q[1].empty()) {
                sol++;
            }
            while (!q[c].empty()) {
                int u = q[c].front();
                q[c].pop();
                for (int i = 0; i < (int) g[u].size(); ++i) {
                    int v = g[u][i];
                    deg[v]--;
                    if (!deg[v]) {
                        q[color[v]].push(v);
                    }
                }
            }
        }
    }
    printf("%d\n", sol);

    return 0;
}
