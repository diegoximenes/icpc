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

int main() {
    int n;
    set<int> lines;
    set<int>::iterator it;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int k;
        set<int> local_lines;

        scanf("%d", &k);
        for (int j = 0; j < k; ++j) {
            int x;
            scanf("%d", &x);
            local_lines.insert(x);
            if (i == 0) {
                lines.insert(x);
            }
        }

        vector<int> to_erase;
        for (it = lines.begin(); it != lines.end(); ++it) {
            if (local_lines.find(*it) == local_lines.end()) {
                to_erase.pb(*it);
            }
        }
        for (int j = 0; j < (int) to_erase.size(); ++j) {
            lines.erase(to_erase[j]);
        }
    }

    bool first = 1;
    for (it = lines.begin(); it != lines.end(); ++it) {
        if (!first) {
            putchar(' ');
        }
        printf("%d", *it);
        first = 0;
    }
    puts("");

    return 0;
}
