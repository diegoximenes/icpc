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

#define MAX 201

char out[MAX];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int cnt_zero, cnt_one;
        scanf("%d %d", &cnt_zero, &cnt_one);

        int turn = 0;
        while (cnt_zero || cnt_one) {
            if (!cnt_zero) {
                out[turn++] = '1';
                cnt_one--;
            } else if(!cnt_one) {
                out[turn++] = '0';
                cnt_zero--;
            } else {
                if (turn & 1) {
                    out[turn++] = '1';
                    cnt_one--;
                } else {
                    out[turn++] = '0';
                    cnt_zero--;
                }
            }
        }
        out[turn] = 0;
        printf("%s\n", out);
    }

    return 0;
}
