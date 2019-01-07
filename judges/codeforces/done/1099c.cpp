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

#define MAX 205

char s[MAX];

int main() {
    int k, n;
    scanf("%s %d", s, &k);

    n = strlen(s);
    bool can_repeat = 0;
    int cnt_special = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '?' || s[i] == '*') {
            cnt_special++;
        }
        if (s[i] == '*') {
            can_repeat = 1;
        }
    }

    bool can = 1;
    vector<char> out;
    if (k >= n - 2 * cnt_special) {
        if (k > n - cnt_special) {
            if (can_repeat) {
                bool first_repeat = 1;
                for (int i = n - 1; i >= 0; --i) {
                    if (s[i] != '?' && s[i] != '*') {
                        out.pb(s[i]);
                    }
                    if (first_repeat && s[i] == '*') {
                        for (int j = 0; j < k - (n - cnt_special); j++) {
                            out.pb(s[i - 1]);
                        }
                        first_repeat = 0;
                    }
                }
            } else {
                can = 0;
            }
        } else {
            int cnt_to_remove = n - cnt_special - k;
            int cnt_removed = 0;
            for (int i = n - 1; i >= 0; --i) {
                if ((s[i] == '?' || s[i] == '*') && cnt_removed < cnt_to_remove) {
                    i--;
                    cnt_removed++;
                } else if (s[i] != '?' && s[i] != '*') {
                    out.pb(s[i]);
                }
            }
        }
    } else {
        can = 0;
    }

    if (!can) {
        puts("Impossible");
    } else {
        for (int i = (int) out.size() - 1; i >= 0; --i) {
            putchar(out[i]);
        }
        puts("");
    }

    return 0;
}
