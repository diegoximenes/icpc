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

#define MAX 10000

int n, m;
pair<int, int> p[MAX];
pair< pair<int, int>, pair<int, int> > pairs[MAX];
bool mark[MAX];
int start;
map<int, int> pair_map;

void print(int id_out) {
    mark[id_out] = 1;
    printf("%d\n", id_out + 1);
    fflush(stdout);
}

int i_pairs;
int i_p;
void get_best(int op) {
    int id_out;
    if (pair_map.find(op) != pair_map.end() && !mark[pair_map[op]]) {
        id_out = pair_map[op];
    } else {
        while (i_pairs >= 0 && mark[pairs[i_pairs].fi.se]){
            i_pairs--;
        }
        if (i_pairs >= 0) {
            id_out = pairs[i_pairs].fi.se;
        } else {
            while (i_p >= 0 && mark[p[i_p].se]){
                i_p--;
            }
            id_out = p[i_p--].se;
        }
    }
    print(id_out);
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < 2 * n; ++i) {
       scanf("%d", &p[i].fi);
       p[i].se = i;
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        --a; --b;
        pair_map[a] = b;
        pair_map[b] = a;
        if (p[a].fi < p[b].fi) {
            swap(a, b);
        }
        pairs[i] = mp(p[a], p[b]);
    }
    scanf("%d", &start);

    sort(pairs, pairs + m);
    sort(p, p + 2 * n);
    memset(mark, 0, sizeof(mark));

    i_pairs = m - 1;
    i_p = 2 * n - 1;
    int op = -1;
    int i_turns = 0;
    while (i_turns < n) {
        if (start == 1) {
            get_best(op);
            scanf("%d", &op);
            mark[--op] = 1;
        } else {
            scanf("%d", &op);
            mark[--op] = 1;
            get_best(op);
        }
        i_turns++;
    }

    return 0;
}
