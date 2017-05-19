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

int sum[MAX], v[MAX], n;
char s[MAX];

int get_sum(int l, int r) {
    if (r >= l) return sum[r] - sum[l - 1];
    return sum[r] + sum[n] - sum[l - 1];
}

int main() {
    ios::sync_with_stdio(false);

    int k, q;
    scanf("%d %d %d", &n, &k, &q);
    k = min(k, n);
    sum[0] = 0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &v[i]);
        sum[i] = sum[i - 1] + v[i];
    }

    multiset<int> tree;
    multiset<int>::iterator it;
    deque< pair<int, int> > dq;
    for (int i = k; i <= n; ++i) {
        int x = sum[i] - sum[i - k];
        dq.pb(mp(i - k + 1, i));
        tree.insert(-x);
    }

    scanf(" %s ", s);
    for (int i = 0; i < q; ++i) {
        if (s[i] == '?') {
            printf("%d\n", -*tree.begin());
        } else if ((int) dq.size() > 1) {
            int l = dq.back().fi, r = dq.back().se;
            dq.pop_back();
            tree.erase(tree.find(-get_sum(l, r)));

            int new_l = r, new_r = dq.front().se;
            new_r--;
            if (new_r == 0) new_r = n;
            dq.push_front(mp(new_l, new_r));
            tree.insert(-get_sum(new_l, new_r));
        }
    }

    return 0;
}
