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

#define MAX 100005
#define LMAX 'z' - 'a' + 1

char s[MAX];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d %s %d", &n, s, &k);
        unordered_set<char> special;
        for (int i = 0; i < k; ++i) {
            char c;
            scanf(" %c", &c);
            special.insert(c);
        }

        int sol = 0, last = -1;
        for (int i = n - 1; i >= 0; --i) {
            if (last != -1) {
                sol = max(sol, last - i);
            }
            if (special.find(s[i]) != special.end()) {
                last = i;
            }
        }
        printf("%d\n", sol);
    }

    return 0;
}
