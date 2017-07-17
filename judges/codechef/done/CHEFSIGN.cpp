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

#define MAX 100005

int n;
char s[MAX], in[MAX];

bool check(int p) {
    if (n == 0) return 1;

    int last = 1;
    if (s[0] == '>') last = p;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == '<' && last == p) return 0;
        if (s[i] == '>' && last == 1) return 0;

        if (s[i] == '<' && s[i + 1] == '>')
            last = p;
        else if (s[i] == '>' && s[i + 1] == '<')
            last = 1;
        else if (s[i] == '<')
            last++;
        else
            last--;
    }
    if (s[n - 1] == '>')
        last--;
    else
        last++;
    return (last >= 1 && last <= p);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf(" %s ", in);

        int n_in = strlen(in);
        n = 0;
        for (int i = 0; i < n_in; ++i)
            if (in[i] != '=')
                s[n++] = in[i];

        int l = 1, r = n + 1, last;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (check(mid)) {
                r = mid - 1;
                last = mid;
            } else {
                l = mid + 1;
            }
        }
        printf("%d\n", last);
    }

    return 0;
}
