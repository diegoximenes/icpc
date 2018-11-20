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

#define MAX 105
#define MAXROW 5
#define MAXCOL 20

char s[MAX];

int main() {
    scanf("%s", s);
    int n = strlen(s);

    for (int r = 1; r <= MAXROW; ++r) {
        for (int c = 1; c <= MAXCOL; ++c) {
            if (r * c >= n) {
                int stars_per_row = (r * c - n) / r;
                int rest_stars_per_row = (r * c - n) % r;

                int l = 0;
                printf("%d %d\n", r, c);
                for (int i = 0; i < r; ++i) {
                    int k = 0;
                    for (k = 0; k < stars_per_row; ++k) {
                        printf("*");
                    }
                    if (rest_stars_per_row) {
                        printf("*");
                        rest_stars_per_row--;
                        k++;
                    }
                    while (k < c) {
                        printf("%c", s[l++]);
                        k++;
                    }
                    puts("");
                }
                return 0;
            }
        }
    }

    return 0;
}
