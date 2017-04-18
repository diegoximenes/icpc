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

void read_ingredients(set<string> &tree) {
    for (int i = 0; i < 4; ++i) {
        string s;
        cin >> s;
        tree.insert(s);
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        set<string> tree1, tree2;
        set<string>::iterator it;

        read_ingredients(tree1);
        read_ingredients(tree2);

        int cnt = 0;
        for (it = tree1.begin(); it != tree1.end(); ++it)
            if (tree2.find(*it) != tree2.end())
                cnt++;
        if (cnt >= 2)
            puts("similar");
        else
            puts("dissimilar");
    }

    return 0;
}
