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

#define MAX 400005

int main() {
    int q, x;
    int mex = 0;
    unordered_set<int> has;
    int min_mod[MAX];

    memset(min_mod, -1, sizeof(min_mod));
    scanf("%d %d", &q, &x);
    while (q--) {
        int y;
        scanf("%d", &y);

        int mod = y % x;
        if (min_mod[mod] == -1) {
            min_mod[mod] = mod;
        } else {
            while (has.find(min_mod[mod]) != has.end()) {
                min_mod[mod] += x;
            }
        }
        has.insert(min_mod[mod]);
        if (min_mod[mod] == mex) {
            while (has.find(mex) != has.end()) {
                mex++;
            }
        }

        printf("%d\n", mex);
    }

    return 0;
}
