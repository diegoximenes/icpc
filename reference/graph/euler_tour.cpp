/*
Euler Tour

Description: Given an undirected graph find a path that starts in a vertex and
finish in the same vertex passing over all edges only once
Caso queira obter o ciclo ordenado de acordo com a numeração da aresta deve-se
ordenar as listas de adjacências de acordo com o número da aresta
O(n + m)

A directed graph without isolated vertices has an eulerian circuit if and only
if the graph is connected and the number of incoming edges into any vertex is
the same as the number of edges leaving that vertex.
*/

#include <bits/stdc++.h>
using namespace std;

#define MAX 60
#define pb push_back
#define mp make_pair

vector< pair<int, bool> > g_[MAX];
int n_;
list<int> cycle_;
bool mark_[MAX];
int deg_[MAX];

bool connected(int s) {
    int count = 0;
    queue<int> q;
    memset(mark_, 0, sizeof(mark_));
    q.push(s);
    mark_[s] = 1;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        ++count;
        for (int i = 0; i < (int) g_[v].size(); ++i) {
            int u = g_[v][i].first;
            if (!mark_[u]) {
                mark_[u] = 1;
                q.push(u);
            }
        }
    }
    return (count == n_);
}

bool eulerian(int s) {
    if (!connected(s)) return 0;
    // for(int i = 0; i < n_; ++i)
    // for based on the problem conditions. In general use the commented for
    for (int i = 0; i < MAX; ++i)
        if (deg_[i] % 2 != 0)
            return 0;
    return 1;
}

void eulerTour(list<int>::iterator it, int v) {
    for (int i = 0; i < (int) g_[v].size(); ++i) {
        pair<int, int> u = g_[v][i];
        // edge wasn't traversed
        if (u.second) {
            g_[v][i].second = 0;
            for (int j = 0; j < (int) g_[u.first].size(); ++j) {
                pair<int, int> uu = g_[u.first][j];
                // if graph is undirected use this to unmark reversed edge
                if(uu.first == v && uu.second) {
                    g_[u.first][j].second = 0;
                    break;
                }
            }
            eulerTour(cycle_.insert(it, v), u.first);
        }
    }
}

// cycle start in vertex s
bool findCycle(int s) {
    if (!eulerian(s)) return 0;

    cycle_.clear(); // cycle will have the reverse order of visitation
    eulerTour(cycle_.begin(), s);

    // print cycle
    for (list<int>::iterator it = cycle_.begin(); ; ++it) {
        list<int>::iterator it2 = ++it; --it;
        if (it2 == cycle_.end()) {
            printf("%d %d\n", *it + 1, *cycle_.begin() + 1);
            break;
        }
        printf("%d %d\n", *it + 1, *it2 + 1);
    }
    return 1;
}

void init(int n) {
    n_ = n;
    memset(deg_, 0, sizeof(deg_));
    // for(int i = 0; i < n_; ++i) g_[i].clear();
    // In general case use the commented for
    for (int i = 0; i < MAX; ++i) g_[i].clear();
}

void add_edge(int u, int v) {
    g_[u].pb(mp(v, 1)); g_[v].pb(mp(u, 1));
    ++deg_[u]; ++deg_[v];
}

int main() {
    int u, v, t, m, s;
    bool color[MAX];

    scanf("%d", &t);
    for (int tc = 1; tc <= t; ++tc) {
        memset(color, 0, sizeof(color)); // problem stuff
        init(0);

        scanf("%d", &m);
        while (m--) {
            scanf("%d %d", &u, &v);
            --u; --v;
            add_edge(u, v);

            // problem stuff
            s = u;
            if (!color[v]) color[v] = 1, ++n_;
            if (!color[u]) color[u] = 1, ++n_;
        }

        printf("Case #%d\n", tc);
        if (!findCycle(s)) puts("some beads may be lost");
        if (tc < t) puts("");
    }

    return 0;
}
