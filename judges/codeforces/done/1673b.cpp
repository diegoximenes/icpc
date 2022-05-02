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

#define MAX 200005
#define LMAX 'z' - 'a' + 5

char s[MAX];
int last[LMAX];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s);
        int n = strlen(s);

        set<char> letters;
        for (int i = 0; i < n; ++i) {
            letters.insert(s[i]);
        }
        int nl = letters.size();

        bool yes = 1;
        memset(last, -1, sizeof(last));
        for (int i = 0; i < n; ++i) {
            int ci = s[i] - 'a';
            if ((last[ci] != -1) && (i - last[ci] < nl)) {
                yes = 0;
                break;
            }
            last[ci] = i;
        }
        yes ? printf("YES\n") : printf("NO\n");
    }

    return 0;
}
