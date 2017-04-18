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

#define MAX 150005

int n, m;
vector<int> g[MAX];
int deg[MAX], mark[MAX];

int dfs(int u, int cc) {
    int ret = 1;
    mark[u] = cc;
    for (int i = 0; i < (int) g[u].size(); ++i) {
        int v = g[u][i];
        if (!mark[v])
            ret += dfs(v, cc);
    }
    return ret;
}

int main() {
    memset(deg, 0, sizeof(deg));
    memset(mark, 0, sizeof(mark));

    scanf("%d %d", &n, &m);
    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--;
        v--;
        g[u].pb(v);
        g[v].pb(u);
        deg[u]++;
        deg[v]++;
    }

    map<int, int> cc_to_size;
    int cc = 1;
    for (int i = 0; i < n; ++i)
        if (!mark[i]) {
            int cc_size = dfs(i, cc);
            cc_to_size[cc++] = cc_size;
        }

    for (int i = 0; i < n; ++i)
        if (deg[i] + 1 != cc_to_size[mark[i]]) {
            puts("NO");
            return 0;
        }
    puts("YES");

    return 0;
}
