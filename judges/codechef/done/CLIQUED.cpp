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

#define MAX 100005

vector< pair<int, ll> > g[MAX];
bool mark[MAX];
ll dist[MAX];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k, x, m, s;
        scanf("%d %d %d %d %d", &n, &k, &x, &m, &s);
        s--;
        for (int i = 0; i < n; ++i) g[i].clear();
        while (m--) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            --u; --v;
            g[u].pb(mp(v, w));
            g[v].pb(mp(u, w));
        }

        memset(mark, 0, sizeof(mark));
        memset(dist, INF, sizeof(dist));
        set< pair<ll, int> > heap;
        heap.insert(mp(0, s));
        dist[s] = 0;
        bool found_clique = 0;
        while (!heap.empty()) {
            int u = heap.begin()->se;
            heap.erase(heap.begin());

            mark[u] = 1;
            if (u < k && !found_clique) {
                found_clique = 1;
                for (int v = 0; v < k; ++v) {
                    heap.erase(mp(dist[v], v));
                    dist[v] = min(dist[v], dist[u] + x);
                    heap.insert(mp(dist[v], v));
                }
            }

            for (int i = 0; i < (int) g[u].size(); ++i) {
                int v = g[u][i].fi;
                ll w = g[u][i].se;
                if (!mark[v] && dist[v] > dist[u] + w) {
                    heap.erase(mp(dist[v], v));
                    dist[v] = dist[u] + w;
                    heap.insert(mp(dist[v], v));
                }
            }
        }

        printf("%lld", dist[0]);
        for (int u = 1; u < n; ++u) printf(" %lld", dist[u]);
        puts("");
    }

    return 0;
}
