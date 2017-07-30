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

#define MAX 1000005
#define MAXL ('z' - 'a' + 2)

char ent[MAX];
int last[MAXL], first[MAXL];

int main() {
    int n, k;
    scanf("%d %d %s", &n, &k, ent);

    memset(first, INF, sizeof(first));
    memset(last, -1, sizeof(last));
    for (int i = 0; i < n; ++i) {
        first[ent[i] - 'A'] = min(first[ent[i] - 'A'], i);
        last[ent[i] - 'A'] = max(first[ent[i] - 'A'], i);
    }

    for (int i = 0; i < n; ++i) {
        int cnt_open = 0;
        for (char c = 'A'; c <= 'Z'; ++c)
            if (i >= first[c - 'A'] && i <= last[c - 'A'])
                cnt_open++;
        if (cnt_open > k) {
            puts("YES");
            return 0;
        }
    }

    puts("NO");

    return 0;
}
