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

#define MAX 200001

char s[MAX];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s);
        int n = strlen(s);

        int cnt_open = 0, cnt_close = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                cnt_open++;
            } else if (s[i] == ')') {
                cnt_close++;
            }
        }

        int cnt_marks_to_open = 0;
        int last_mark_to_open = -1, first_mark_to_close = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '?') {
                if (cnt_open + cnt_marks_to_open < n / 2) {
                    s[i] = '(';
                    cnt_marks_to_open++;
                    last_mark_to_open = i;
                } else {
                    s[i] = ')';
                    if (first_mark_to_close == -1) {
                        first_mark_to_close = i;
                    }
                }
            }
        }

        bool more_than_one = 0;
        if (last_mark_to_open != -1 && first_mark_to_close != -1) {
            s[last_mark_to_open] = ')';
            s[first_mark_to_close] = '(';

            more_than_one = 1;
            cnt_open = cnt_close = 0;
            for (int i = 0; i < n; ++i) {
                if (s[i] == '(') {
                    cnt_open++;
                } else {
                    cnt_close++;
                }
                if (cnt_close > cnt_open) {
                    more_than_one = 0;
                }
            }
        }

        printf("%s\n", more_than_one ? "NO" : "YES");
    }

    return 0;
}
