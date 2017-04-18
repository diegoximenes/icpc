/*
Maximum matching in bipartite graph
O(|E|*sqrt(|V|))
*/

#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

#define mp make_pair
#define pb push_back

#define MAX 100010
#define INF 0x3f3f3f3f
#define NIL 0

vector<int> g_[MAX];
int match_[MAX], dist_[MAX], n_left_, n_right_;
// n_left == number of vertices in the left side
// n_right == number of vertices in the right side
// indices for left side: 1...n_left
// indices for right side: (n_left + 1)...n_right
// only need edge from left to right

bool bfs() {
    int i, u, v;
    queue<int> q;
    for (i = 1; i <= n_left_; ++i) {
        if (match_[i] == NIL) {
            dist_[i] = 0;
            q.push(i);
        } else {
            dist_[i] = INF;
        }
    }
    dist_[NIL] = INF;
    while (!q.empty()) {
        u = q.front(); q.pop();
        if (u != NIL) {
            for (i = 0; i < (int) g_[u].size(); ++i) {
                v = g_[u][i];
                if (dist_[match_[v]] == INF) {
                    dist_[match_[v]] = dist_[u] + 1;
                    q.push(match_[v]);
                }
            }
        }
    }
    return (dist_[NIL] != INF);
}

bool dfs(int u) {
    int i, v;
    if (u != NIL) {
        for (i = 0; i < (int) g_[u].size(); ++i) {
            v = g_[u][i];
            if (dist_[match_[v]] == dist_[u] + 1 && dfs(match_[v])) {
                match_[v] = u; match_[u] = v;
                return 1;
            }
        }
        dist_[u] = INF;
        return 0;
    }
    return 1;
}

int hopcroft_karp() {
    int matching = 0, i;
    for (int i = 0; i <= n_left_ + n_right_; ++i) match_[i] = NIL;
    while (bfs())
        for (i = 1; i <= n_left_; ++i)
            if (match_[i] == NIL && dfs(i))
                ++matching;
    return matching;
}

void add_edge(int u, int v) {
    g_[u].pb(v);
}

void init(int n_left, int n_right) {
    n_left_ = n_left;
    n_right_ = n_right;
    for (int i = 0; i <= n_left_ + n_right_; ++i) g_[i].clear();
}

// return indice of vertices from right side. indice of vertices of the vertice
// side don't need adjusts
inline int id_right(int u) {
    return n_left_ + u;
}

int main() {
    int e, u, v, n_left, n_right;

    scanf("%d %d %d", &n_left, &n_right, &e);
    init(n_left, n_right);
    while (e--) {
        scanf("%d %d", &u, &v);
        add_edge(u, id_right(v));
    }
    printf("%d\n", hopcroft_karp());

    return 0;
}

