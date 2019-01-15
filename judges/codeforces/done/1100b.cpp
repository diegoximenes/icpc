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
    int n, m;
    scanf("%d %d", &n, &m);

    map<int, int> cnt;
    map<int, int>::iterator it;
    while (m--) {
        int x;
        scanf("%d", &x);
        if (cnt.find(x) == cnt.end()) {
            cnt[x] = 1;
        } else {
            cnt[x]++;
        }

        vector<int> to_erase;
        if ((int) cnt.size() == n) {
            putchar('1');
            for (it = cnt.begin(); it != cnt.end(); ++it) {
                cnt[it->fi]--;
                if (cnt[it->fi] == 0) {
                    to_erase.pb(it->fi);
                }
            }
            for (int i = 0; i < (int) to_erase.size(); ++i) {
                cnt.erase(to_erase[i]);
            }
        } else {
            putchar('0');
        }
    }
    puts("");

    return 0;
}
