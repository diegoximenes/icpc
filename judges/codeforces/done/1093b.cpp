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

#define MAX 1005

char s[MAX];
int cnt[MAX];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s);

        int n = strlen(s);
        bool solved = 0;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; ++i) {
            cnt[s[i] - 'a']++;
        }
        for (char c = 'a'; c <= 'z'; ++c) {
            if (cnt[c - 'a'] == n) {
                printf("-1");
                solved = 1;
            }
        }
        if (!solved) {
            for (char c = 'a'; c <= 'z'; ++c) {
                while (cnt[c - 'a']) {
                    printf("%c", c);
                    cnt[c - 'a']--;
                }
            }
        }
        puts("");
    }

    return 0;
}
