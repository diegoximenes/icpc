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

vector<int> island[MAX];
int cnt_dish[MAX];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);

        memset(cnt_dish, 0, sizeof(cnt_dish));
        for (int i = 0; i < n; ++i) {
            island[i].clear();

            int p;
            scanf("%d", &p);
            for (int j = 0; j < p; ++j) {
                int x;
                scanf("%d", &x);
                x--;
                island[i].pb(x);
                cnt_dish[x]++;
            }
        }

        bool solved = 0;
        for (int i = 0; i < k; ++i)
            if (cnt_dish[i] == 0) {
                puts("sad");
                solved = 1;
                break;
            }
        if (solved) continue;

        for (int i = 0; i < n; ++i) {
            bool can = 1;
            for (int j = 0; j < (int) island[i].size(); ++j)
                if (cnt_dish[island[i][j]] - 1 == 0)
                    can = 0;
            if (can) {
                puts("some");
                solved = 1;
                break;
            }
        }
        if(solved) continue;

        puts("all");
    }

    return 0;
}
