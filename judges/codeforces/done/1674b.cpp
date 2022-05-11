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
    map< pair<char, char>, int> w_id;
    for (char c1 = 'a'; c1 <= 'z'; ++c1) {
        for (char c2 = 'a'; c2 <= 'z'; ++c2) {
            if (c1 != c2) {
                w_id[mp(c1, c2)] = w_id.size() + 1;
            }
        }
    }

    int t;
    scanf("%d", &t);
    while (t--) {
        char w[3];
        scanf("%s", w);
        printf("%d\n", w_id[mp(w[0], w[1])]);
    }

    return 0;
}
