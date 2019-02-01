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

#define MAX 505

int n;
char g[MAX][MAX];
const int cnt_neigh = 4;
const int neigh[4][2] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

bool in(int i, int j) {
    return (i >= 0 && i < n && j >= 0 && j < n);
}

int is_cross(int i, int j) {
    if (g[i][j] != 'X') {
        return 0;
    }

    for (int k = 0; k < cnt_neigh; ++k) {
        int ni = i + neigh[k][0];
        int nj = j + neigh[k][1];
        if (!in(ni, nj) || (g[ni][nj] != 'X')) {
            return 0;
        }
    }

    return 1;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", g[i]);
    }

    int sol = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            sol += is_cross(i, j);
        }
    }

    printf("%d\n", sol);

    return 0;
}
