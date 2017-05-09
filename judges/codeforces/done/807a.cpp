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

#define MAX 1005

pair<int, int> v[MAX];

int main() {
    ios::sync_with_stdio(false);

    int n;
    scanf("%d", &n);

    bool rated = 0;
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        v[i] = mp(a, b);
        if (a != b) rated = 1;
    }

    if (rated) {
        puts("rated");
    } else {
        bool unrated = 0;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (v[i].fi < v[j].fi)
                    unrated = 1;

        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (v[i].fi == v[j].fi && v[j - 1].fi != v[j].fi)
                    unrated = 1;

        if (unrated) {
            puts("unrated");
        } else {
            puts("maybe");
        }
    }

    return 0;
}
