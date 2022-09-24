#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

#ifdef LOCAL
#define debug(...)                    \
    {                                 \
        fprintf(stderr, __VA_ARGS__); \
        fflush(stderr);               \
    }
#else
#define debug(...)
#endif

const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1);
const double EPS = 1e-9;

inline int cmp_double(double x, double y, double tol = EPS) {
    // (x < y): -1, (x == y): 0, (x > y): 1
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

template <class T>
inline void print_array(T *v, int n) {
    if (n > 0) {
        cout << v[0];
    }
    for (int i = 1; i < n; ++i) {
        cout << " " << v[i];
    }
    cout << endl;
}

template <class T>
inline void read_array(T *v, int n, int start = 0) {
    for (int i = start; i < start + n; ++i) {
        cin >> v[i];
    }
}

template <class T>
inline void print_vector(const vector<T> &v) {
    if (!v.empty()) {
        cout << v[0];
    }
    for (int i = 1; i < (int) v.size(); ++i) {
        cout << " " << v[i];
    }
    cout << endl;
}

template <class T>
inline void read_vector(vector<T> &v, int n, int start = 0) {
    for (int i = start; i < start + n; ++i) {
        cin >> v[i];
    }
}

#define MAX 100000

int n;
int tree[4 * MAX];
pair<int, int> a[MAX], b[MAX];
int pos_b[MAX];

int query(int node, int node_l, int node_r, int q_l, int q_r) {
    if (node_l > q_r || node_r < q_l) {
        return 0;
    }
    if (node_l >= q_l && node_r <= q_r) {
        return tree[node];
    }

    int left = node << 1;
    int right = left + 1;
    int mid = node_l + (node_r - node_l) / 2;
    int ret = query(left, node_l, mid, q_l, q_r) +
              query(right, mid + 1, node_r, q_l, q_r);
    return ret;
}
int query(int q_l, int q_r) {
    return query(1, 1, n, q_l, q_r);
}

void update(int node, int node_l, int node_r, int pos, int v) {
    if (node_l == node_r) {
        tree[node] = v;
    } else {
        int left = node << 1;
        int right = left + 1;
        int mid = node_l + (node_r - node_l) / 2;
        if (pos <= mid) {
            update(left, node_l, mid, pos, v);
        } else {
            update(right, mid + 1, node_r, pos, v);
        }
        tree[node] = tree[left] + tree[right];
    }
}
void update(int pos, int v) {
    update(1, 1, n, pos, v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;

        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i].first;
            b[i].second = i;

            update(i + 1, 1);
        }

        sort(a, a + n);
        sort(b, b + n);
        for (int i = 0; i < n; ++i) {
            pos_b[b[i].second] = i;
        }

        int cnt_max_strength = 0;
        for (int i = 0; i < n; ++i) {
            int strength = i + query(1, pos_b[a[i].second] + 1) - 1;
            if (strength == n - 1) {
                cnt_max_strength++;
            }
            update(pos_b[a[i].second] + 1, 0);
        }
        cout << cnt_max_strength << endl;
    }

    return 0;
}
