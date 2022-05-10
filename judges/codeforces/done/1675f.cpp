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

vector<int> g[MAX];
int dist[MAX], dad[MAX];
int n, k;
int sol;
bool mark[MAX];

void bfs(vector<int> &sources) {
    for (int u = 0; u < n; ++u) {
        dist[u] = INF;
    }
    queue<int> q;
    for (int i = 0; i < (int) sources.size(); ++i) {
        int u = sources[i];
        dist[u] = 0;
        dad[u] = -1;
        q.push(u);
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < (int) g[u].size(); ++i) {
            int v = g[u][i];
            if (dist[v] == INF) {
                dad[v] = u;
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &k);

        for (int u = 0; u < n; ++u) {
            g[u].clear();
        }

        int x, y;
        scanf("%d %d", &x, &y);
        --x;
        --y;

        vector<int> things;
        for (int i = 0; i < k; ++i) {
            int thing;
            scanf("%d", &thing);
            things.pb(thing - 1);
        }
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            scanf("%d %d", &u, &v);
            --u;
            --v;
            g[u].pb(v);
            g[v].pb(u);
        }

        vector<int> source_x{x};
        bfs(source_x);
        sol = dist[y];

        vector<int> x_y_path;
        int u = y;
        while (u != -1) {
            x_y_path.pb(u);
            u = dad[u];
        }

        bfs(x_y_path);
        for (int i = 0; i < (int) things.size(); ++i) {
            int u = things[i];
            while (dad[u] != -1) {
                sol += 2;
                int dad_u = dad[u];
                dad[u] = -1;
                u = dad_u;
            }
        }

        printf("%d\n", sol);
    }

    return 0;
}
