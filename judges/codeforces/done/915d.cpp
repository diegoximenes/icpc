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

#define MAX 505

int n, m;
int indeg[MAX], out_indeg[MAX];
vector<int> g[MAX], grev[MAX];

bool is_dag(int delu, int delv, int *l_indeg) {
    for (int i = 0; i < n; ++i) l_indeg[i] = 0;
    for (int u = 0; u < n; ++u) {
        for (int i = 0; i < (int) g[u].size(); ++i) {
            int v = g[u][i];
            if (u == delu && v == delv) continue;
            l_indeg[v]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (l_indeg[i] == 0) {
            q.push(i);
        }
    }
    int cnt = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cnt++;
        for (int i = 0; i < (int) g[u].size(); ++i) {
            int v = g[u][i];
            if (u == delu && v == delv) continue;
            l_indeg[v]--;
            if (l_indeg[v] == 0) {
                q.push(v);
            }
        }
    }
    return cnt == n;
}

int main() {
    scanf("%d %d", &n, &m);
    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        --u; --v;
        g[u].pb(v);
        grev[v].pb(u);
    }

    if (is_dag(-1, -1, out_indeg)) {
        puts("YES");
        return 0;
    }

    for (int u = 0; u < n; ++u) {
        if (out_indeg[u] == 1) {
            for (int i = 0; i < (int) grev[u].size(); ++i) {
                int v = grev[u][i];
                if (is_dag(v, u, indeg)) {
                    puts("YES");
                    return 0;
                }
            }
        }
    }

    puts("NO");

    return 0;
}
