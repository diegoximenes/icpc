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

#define MAX 100005
const ll MODLL = 1000000007LL;

int cnt_sets;
int union_find_set[MAX];

void init(int n) {
    cnt_sets = n;
    for (int i = 1; i <= n; ++i) {
        union_find_set[i] = i;
    }
}

int find(int i) {
    return union_find_set[i] = (union_find_set[i] == i) ?
        union_find_set[i] :
        find(union_find_set[i]);
}

void merge(int i, int j) {
    if (find(j) != find(i)) {
        cnt_sets--;
        union_find_set[find(j)] = find(i);
    }
}

int a[MAX], b[MAX], c[MAX];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        int c_not_empty = 0;
        for (int i = 0; i < n; ++i) {
            cin >> c[i];

            if (c[i] == 0) {
                if (a[i] == b[i]) {
                    c[i] = a[i];
                }
            }
            if (c[i]) {
                c_not_empty = c[i];
            }
        }

        init(n);
        for (int i = 0; i < n; ++i) {
            if (c[i] == 0) {
                merge(a[i], b[i]);
            } else if (c_not_empty) {
                merge(c[i], c_not_empty);
            }
        }

        ll sol = 1;
        for (int i = 0; i < cnt_sets - 1; ++i) {
            sol = (sol << 1) % MODLL;
        }
        if (!c_not_empty) {
            sol = (sol << 1) % MODLL;
        }
        cout << sol << endl;
    }

    return 0;
}
