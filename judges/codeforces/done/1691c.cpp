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

#define MAX 100001

char s[MAX];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d %d %s", &n, &k, s);

        int first1 = n, last1 = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                first1 = min(first1, i);
                last1 = max(last1, i);
            }
        }

        if (last1 != -1) {
            if ((s[0] == '1') && (s[n - 1] == '0')) {
                if (k >=  n - 1 - last1) {
                    swap(s[last1], s[n - 1]);
                }
            } else if ((s[0] == '0') && (s[n - 1] == '1')) {
                if ((first1 != last1) && (k >= first1)) {
                    swap(s[0], s[first1]);
                }
            } else if((s[0] == '0') && (s[n - 1] == '0')) {
                if (last1 == first1) {
                    if (k >=  n - 1 - last1) {
                        swap(s[n - 1], s[last1]);
                    } else if (k >= first1) {
                        swap(s[0], s[first1]);
                    }
                } else {
                    if (k >= n - 1 - last1 + first1) {
                        swap(s[0], s[first1]);
                        swap(s[n - 1], s[last1]);
                    } else if (k >=  n - 1 - last1) {
                        swap(s[n - 1], s[last1]);
                    } else if (k >= first1) {
                        swap(s[0], s[first1]);
                    }
                }
            }
        }

        int sum = 0;
        if (s[0] == '1') {
            sum += 10;
        }
        for (int i = 1; i < n - 1; ++i) {
            if (s[i] == '1') {
                sum += 11;
            }
        }
        if (s[n - 1] == '1') {
            sum += 1;
        }
        printf("%d\n", sum);
    }

    return 0;
}
