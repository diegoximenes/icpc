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

#define MAX 105

char n[MAX], out1[MAX], out2[MAX];

void print_number(char s[MAX], int len) {
    bool leading_zero = 1;
    for (int i = 0; i < len; ++i) {
        if (s[i] == '0' && leading_zero) {
            continue;
        }
        leading_zero = 0;
        printf("%c", s[i]);
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; ++tc) {
        scanf(" %s ", n);
        int len = strlen(n);
        for (int i = 0; i < len; ++i) {
            if (n[i] == '4') {
                out1[i] = out2[i] = '2';
            } else {
                out1[i] = n[i];
                out2[i] = '0';
            }
        }

        printf("Case #%d: ", tc);
        print_number(out1, len);
        printf(" ");
        print_number(out2, len);
        printf("\n");
    }

    return 0;
}
