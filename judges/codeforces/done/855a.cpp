#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast_io ios::sync_with_stdio(false)
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

int main() {
    set<string> tree;
    int n;

    cin >> n;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        if (tree.find(s) != tree.end()) {
            puts("YES");
        } else {
            puts("NO");
        }
        tree.insert(s);
    }


    return 0;
}
