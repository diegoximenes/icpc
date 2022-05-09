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

#define MAX 5005

int n;
int p[MAX];

ll seg_tree[4 * MAX];

ll insert(int node, int l, int r, int pos, int value) {
    if (l == r) {
        return seg_tree[node] = value;
    }

    int mid = l + (r - l) / 2;
    int node_l = 2 * node;
    int node_r = 2 * node + 1;
    if (pos <= mid) {
        insert(node_l, l, mid, pos, value);
    } else {
        insert(node_r, mid + 1, r, pos, value);
    }

    return seg_tree[node] = seg_tree[node_l] + seg_tree[node_r];
}

void insert(int pos, int value) {
    insert(1, 1, n, pos, value);
}

ll query(int node, int l, int r, int q_l, int q_r) {
    if ((q_l > r) || (q_r < l) || (q_r < q_l)){
        return 0;
    }
    if ((l >= q_l) && (r <= q_r)) {
        return seg_tree[node];
    }

    int mid = l + (r - l) / 2;
    int node_l = 2 * node;
    int node_r = 2 * node + 1;
    return query(node_l, l, mid, q_l, q_r) + query(node_r, mid + 1, r, q_l, q_r);
}

ll query(int l, int r) {
    return query(1, 1, n, l, r);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> p[i];
        }

        for (int i = 1; i <= 4 * n; ++i) {
            seg_tree[i] = 0;
        }

        ll sol = 0;
        insert(p[1], 1);
        for (int b = 2; b <= n - 2; ++b) {
            ll cnt_a_c = query(1, p[b + 1] - 1);
            for (int d = b + 2; d <= n; ++d) {
                if (p[b] > p[d]) {
                    sol += cnt_a_c;
                }
                cnt_a_c += query(1, p[d] - 1);
            }
            insert(p[b], 1);
        }

        cout << sol << endl;
    }

    return 0;
}
