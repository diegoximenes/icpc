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

#define MAX 200001

int segtree_size;
ll segtree[4 * MAX];

ll query(int node, int node_l, int node_r, int q_l, int q_r) {
    if (q_l > node_r || q_r < node_l) {
        // cout << "node=" << node << ", node_l=" << node_l << ", node_r=" << node_r << ", 0" << endl;
        return 0;
    }
    if (node_l >= q_l && node_r <= q_r) {
        // cout << "node=" << node << ", node_l=" << node_l << ", node_r=" << node_r << ", segtree[node]=" << segtree[node] << endl;
        return segtree[node];
    }
    int node_left = node << 1;
    int node_right = (node << 1) + 1;
    int mid = node_l + (node_r - node_l) / 2;
    ll ret = max(query(node_left, node_l, mid, q_l, q_r),
                 query(node_right, mid + 1, node_r, q_l, q_r));
    // cout << "node=" << node << ", node_l=" << node_l << ", node_r=" << node_r << ", ret=" << ret << endl;
    return ret;
}
int query(int l, int r) {
    return query(1, 1, segtree_size, l, r);
}

void update(int node, int node_l, int node_r, int pos, ll val) {
    if (pos < node_l || pos > node_r) {
        return;
    }
    if (node_l == node_r) {
        // cout << "update, node=" << node << ", node_l=" << node_l << ", node_r=" << node_r << ", val=" << val << endl;
        segtree[node] = val;
    } else {
        int node_left = node << 1;
        int node_right = (node << 1) + 1;
        int mid = node_l + (node_r - node_l) / 2;
        if (pos <= mid) {
            update(node_left, node_l, mid, pos, val);
        } else {
            update(node_right, mid + 1, node_r, pos, val);
        }
        segtree[node] = max(segtree[node_left], segtree[node_right]);
    }
}
void update(int pos, int val) {
    update(1, 1, segtree_size, pos, val);
}

int main() {
    fast_io;
    ll n, m;
    cin >> n >> m;
    segtree_size = m;
    for (int i = 1; i <= m; ++i) {
        ll a;
        cin >> a;
        update(i, a);
    }
    int q;
    cin >> q;
    while (q--) {
        int xs, ys, xf, yf, k;
        cin >> xs >> ys >> xf >> yf >> k;

        bool can = 1;
        if (yf < ys) {
            swap(xs, xf);
            swap(ys, yf);
        }

        if (((yf - ys) % k != 0) || ((xf - xs) % k != 0)) {
            can = 0;
        }
        ll max_y = query(ys, yf);
        ll cnt_ops = (n - xs) / k;
        // cout << "max_y=" << max_y << ", xs=" << xs << ", cnt_ops=" << cnt_ops << ", ys=" << ys << ", yf=" << yf << endl;
        if (xs + k * cnt_ops <= max_y) {
            can = 0;
        }

        cout << (can ? "YES" : "NO") << endl;
    }

    return 0;
}
