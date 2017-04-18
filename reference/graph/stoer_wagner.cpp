/*
Stoer-Wagner
O(n*m + (n**2)*logn) - talvez seja o(n**3)

Description: MinCut of an undirected graph
Teste: 10989 (uva)
*/

#include<cstdio>
#include<climits>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAX 155

int g_[MAX][MAX], n_;
int w_[MAX];
bool a_[MAX], merged_[MAX];

int stoer_wagner() {
    int best = INT_MAX;
    memset(merged_, 0, sizeof(merged_));
    merged_[0] = 1;

    for (int phase = 1; phase < n_; ++phase) {
        a_[0] = 1;
        for (int i = 1; i < n_; ++i) {
            if (merged_[i]) continue;
            a_[i] = 0;
            w_[i] = g_[0][i];
        }

        int prev = 0, next;
        for (int i = n_ - 1 - phase; i >= 0; --i) {
            // find next vertex which is not in a
            next = -1;
            for (int j = 1; j < n_; ++j)
                if(!a_[j] && (next == -1 || w_[j] > w_[next]))
                    next = j;
            a_[next] = 1;
            if (i > 0) {
                prev = next;
                //update weights
                for (int j = 1; j < n_; ++j)
                    if (!a_[j])
                        w_[j] += g_[next][j];
            }
        }

        best = min(best, w_[next]);

        // merge s and t
        for (int i = 0; i < n_; ++i) {
            g_[i][prev] += g_[next][i];
            g_[prev][i] += g_[next][i];
        }
        merged_[next] = 1;
    }
    return best;
}

void init(int n) {
    n_ = n;
    memset(g_, 0, sizeof(g_));
}

void add_edge(int u, int v, int cap) {
    g_[u][v] = g_[v][u] = cap;
}

int main() {
    int t, n, m, u, v, cap;

    scanf("%d", &t);
    for (int tc = 1; tc <= t; ++tc) {
        scanf("%d %d", &n, &m);
        init(n);
        while (m--) {
            scanf("%d %d %d", &u, &v, &cap);
            --v; --u;
            add_edge(u, v, cap);
        }
        printf("Case #%d: %d\n", tc, stoer_wagner());
    }

    return 0;
}

