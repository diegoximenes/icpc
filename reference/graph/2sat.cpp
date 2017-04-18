/*
2SAT

Description: (a v b) ^ (not(a) v c) ^ ... ^ (not(c) v d). n is the number of
boolean variables
Discover if there is a configuration that the expression is true. O(n).
If there is a configuration find a valid configuration. O(n*n)

Solution:
a v b == not(a) -> b == not(b) -> a
Create implication graph G: add edges (not(a), b), (not(b), a), considering
second and third expressions above.
if for any a there exists paths from a to not(a) and from not(a) to a then
return UNSATISFIABLE else return SATISFIABLE
To find a configuration: force a to be true (add edge (not(a), a)) and verify
if there is a valid configuration.
Else verify if there is valid configuration with a = false
(add egde(a, not(a))). Do this with all variables.

Corner case:
(expression) ^ a : add only (not(a), a) edge
(expression) ^ not(a) : add only (a, not(a)) edge
*/

#include <bits/stdc++.h>
using namespace std;

#define MAX 1010
#define WHITE -1
#define pb push_back

// problem variables
int b, m, k;

// 2 sat variables
vector<int> g[MAX], s;
//n number of boolean variables (considering a and not(a))
int n, dfs_counter, num_scc, low[MAX], num[MAX], component[MAX];
bool mark[MAX];

void tarjan(int u) {
    low[u] = num[u] = dfs_counter++;
    s.pb(u);
    mark[u] = 1;

    for (int i = 0; i < (int) g[u].size(); ++i) {
        int v = g[u][i];
        if (num[v] == WHITE) tarjan(v);
        if (mark[v]) low[u] = min(low[u], low[v]);
    }

    if (low[u] == num[u]) {
        ++num_scc;
        while (1) {
            int v = s.back();
            s.pop_back();
            mark[v] = 0;
            component[v] = num_scc;
            if (u == v) break;
        }
    }
}

// returns id of not(i)
// id of a is even. Id of not(a) == id(i) + 1
inline int not_id(int i) {
    if (i % 2 == 0) return i + 1;
    return i - 1;
}

void inline init_tarjan() {
    s.clear();
    dfs_counter = num_scc = 0;
    for (int i = 0; i < n; ++i) {
        mark[i] = 0;
        low[i] = 0;
        num[i] = component[i] = WHITE;
    }
    for (int i = 0; i < n; ++i)
        if (num[i] == WHITE)
            tarjan(i);
}

// 2sat verification
inline bool verify() {
    bool sat = 1;
    for (int i = 0; i < n && sat; i += 2) //for don't iterate over not
        if (component[i] == component[not_id(i)])
            sat = 0;
    return sat;
}

// condition variable i to be true. If this condition satisfy return true,
// else return false
inline bool condition_variable(int i) {
    g[not_id(i)].pb(i);
    init_tarjan();
    bool can = verify();
    g[not_id(i)].pop_back();
    return can;
}

int main() {
    for (int tc = 1; scanf("%d %d", &m, &b) && b; ++tc) {
        n = 2 * m;

        // clear graph
        for (int i = 0; i <= n; ++i) g[i].clear();

        // read data
        while (b--) {
            int vote[4];
            scanf("%d", &k);
            for (int i = 0; i < k; ++i) {
                int v;
                char op;
                scanf("%d %c", &v, &op);
                --v;
                if (op == 'y')
                    vote[i] = not_id(2 * v);
                else
                    vote[i] = 2 * v;
            }

            if (k <= 2) {
                for (int i = 0; i < k; ++i)
                    g[not_id(vote[i])].pb(vote[i]);
            } else {
                for (int i = 0; i < k; ++i)
                    for (int j = i + 1; j < k; ++j) {
                        g[not_id(vote[i])].pb(vote[j]);
                        g[not_id(vote[j])].pb(vote[i]);
                    }
            }
        }

        init_tarjan();

        // 2sat verification
        bool sat = verify();

        printf("Case %d: ", tc);
        // condition variables to find a true configuration
        if(sat) {
            for (int i = 0; i < n; i += 2) {
                bool a = condition_variable(i);
                bool b = condition_variable(not_id(i));

                if (a && b)
                    putchar('?'); //i can be true or false
                else if (b)
                    putchar('y'); //i must be false
                else
                    putchar('n'); //is must be true
            }
            puts("");
        } else {
            puts("impossible");
        }
    }

    return 0;
}
