//O(|E|*sqrt(|V|))

#include<cstdio>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

#define mp make_pair
#define pb push_back

#define MAX 2010
#define INF (int)1e9
#define NIL 0

vector<int> g_[MAX];
// n_ == number of vertices in the left side
// m_ == number of vertices in the right side
// indices for left side: 1...n, indices for right side: n+1...m
// only need edge from left to right
int match_[MAX], dist_[MAX], n_, m_;
// used in vertex cover algorithm,
// if sett[u] == 0 and u is in the left side so u is in the vertex cover.
// If sett[u] == 1 and u is in the right side so u is in the vertex cover;
bool sett_[MAX];
bool mark_[MAX];

bool bfs() {
    int i, u, v;
    queue<int> q;
    for (i = 1; i <= n_; ++i) {
        if (match_[i] == NIL) {
            dist_[i] = 0;
            q.push(i);
        }
        else {
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
    for (int i = 0; i <= n_ + m_; ++i) match_[i] = NIL;
    while (bfs())
        for (i = 1; i <= n_; ++i)
            if (match_[i] == NIL && dfs(i))
                ++matching;
    return matching;
}

// return indice of vertices from right side. indice of vertices of the
// vertice side don't need adjusts
inline int indm(int u) {
    return n_ + u;
}

void increase_set(int u) {
    for (int i = 0; i < (int) g_[u].size(); ++i) {
        int v = g_[u][i];
        sett_[v] = mark_[v] = 1;
        if (!mark_[match_[v]]) {
            sett_[match_[v]] = mark_[match_[v]] = 1;
            increase_set(match_[v]);
        }
    }
}

void vertex_cover_bipartite() {
    for (int i = 1; i <= n_; ++i) {
        if (match_[i] == NIL)
            sett_[i] = 1;
        else
            sett_[i] = 0;
    }
    for (int i = 1; i <= m_; ++i) sett_[indm(i)] = 0;
    memset(mark_, 0, sizeof(mark_));

    for (int i = 1; i <= n_; ++i)
        if (sett_[i] && !mark_[i]) {
            mark_[i] = 1;
            increase_set(i);
        }

    // print solution
    for (int i = 1; i <= n_; ++i)
        if (sett_[i] == 0)
            printf(" r%d", i);
    for (int i = 1; i <= m_; ++i)
        if (sett_[indm(i)] == 1)
            printf(" c%d", i);
    puts("");
}

void init(int n, int m) {
    n_ = n;
    m_ = m;
    for (int i = 0; i <= n + m; ++i) g_[i].clear();
}

int main() {
    int n, m, e, u, v;

    while (scanf("%d %d %d", &n, &m, &e) && (n && m && e)) {
        init(n, m);
        while (e--) {
            scanf("%d %d", &u, &v);
            g_[u].pb(indm(v));
            g_[indm(v)].pb(u);
        }

        printf("%d", hopcroft_karp());
        vertex_cover_bipartite();
    }

    return 0;
}

