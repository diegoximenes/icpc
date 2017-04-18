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

int tree_[MAX], n_;

inline int query(int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += tree_[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

inline int query(int a, int b) {
    return query(b) - query(a - 1);
}

inline void update(int idx, int val) {
    while (idx <= n_) {
        tree_[idx] += val;
        idx += (idx & -idx);
    }
}

void init(int n) {
    n_ = n;
    memset(tree_, 0, sizeof(tree_));
}

class Query {
public:
    int id, l, r, k;
    Query(int _id, int _l, int _r, int _k) : id(_id), l(_l), r(_r), k(_k) {}
    bool operator<(Query o) {
        if (k != o.k) return (k < o.k);
        if (id != o.id) return (id < o.id);
        if (l != o.l) return (l < o.l);
        return (r < o.r);
    }
};

int v[MAX], out[MAX];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, q;
        scanf("%d %d", &n, &q);
        for (int i = 0; i < n; ++i) scanf("%d", &v[i]);

        map< pair<int, int>, int> block_id;

        int left = 0;
        vector< pair<int, pair<int, int> > > blocks;
        for (int i = 1; i < n; ++i) {
            if (v[i] != v[i - 1]) {
                pair<int, int> block = mp(left, i - 1);
                block_id[block] = block_id.size() + 1;
                blocks.pb(mp(i - left, block));
                left = i;
            }
        }
        pair<int, int> block = mp(left, n - 1);
        block_id[block] = block_id.size() + 1;
        blocks.pb(mp(n - left, block));
        sort(blocks.begin(), blocks.end());

        init(blocks.size() + 1);

        // for (int i = 0; i < (int) blocks.size(); ++i)
        //     printf("i=%d, block=(%d, (%d, %d))\n",
        //            i, blocks[i].fi, blocks[i].se.fi, blocks[i].se.se);

        vector<Query> queries;
        for (int i = 0; i < q; ++i) {
            int l, r, k;
            scanf("%d %d %d", &l, &r, &k);
            --l; --r;
            queries.pb(Query(i, l, r, k));
        }
        sort(queries.begin(), queries.end());

        int last_k = -1, id_block = blocks.size() - 1;
        set< pair<int, int> > tree, tree_2, tree_3;
        set< pair<int, int> >::iterator it, it_l, it_r;
        for (int i = (int) queries.size() - 1; i >= 0; --i) {
            int l = queries[i].l, r = queries[i].r, k = queries[i].k;

            if (k != last_k) {
                last_k = k;
                for (; id_block >= 0 && blocks[id_block].fi >= k; --id_block) {
                    // printf("id_block=%d\n", id_block);
                    tree.insert(blocks[id_block].se);
                    tree_2.insert(mp(-blocks[id_block].se.se,
                                     blocks[id_block].se.fi));
                    tree_3.insert(mp(blocks[id_block].se.se,
                                     blocks[id_block].se.fi));
                    update(block_id[blocks[id_block].se], 1);
                }
            }

            int sol = 0;

            it_l = tree.lower_bound(mp(l, -1));
            if (it_l != tree.end() && it_l->se <= r) {
                it_r = tree_2.lower_bound(mp(-r, -1));
                int a = block_id[*it_l];
                int b = block_id[mp(it_r->se, -it_r->fi)];
                sol += query(a, b);
            }

            bool get_next = 1;
            it = tree_3.upper_bound(mp(r, INF));
            if (it != tree_3.end()) {
                if (it->se <= l) get_next = 0;
                sol += (min(r, it->fi) - max(l, it->se) + 1 >= k);
            }

            if (get_next) {
                it = tree_3.lower_bound(mp(l, -1));
                if (it != tree_3.end() && it->se < l) {
                    sol += (min(r, it->fi) - max(l, it->se) + 1 >= k);
                }
            }

            out[queries[i].id] = sol;

            // printf("id=%d, l=%d, r=%d, k=%d, sol=%d\n",
            //        queries[i].id, l, r, k, sol);
        }

        for (int i = 0; i < q; ++i) printf("%d\n", out[i]);
    }

    return 0;
}
