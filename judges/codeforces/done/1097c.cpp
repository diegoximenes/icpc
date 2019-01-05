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

#define MAX 500005

char s[MAX];

int main() {
    int n, cnt_ok = 0;
    map<int, int> tree_left, tree_right;
    map<int, int>::iterator it;

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        int len = strlen(s);

        int cnt_open = 0, cnt_left = 0;
        for (int i = 0; i < len; ++i) {
            if (s[i] == '(') {
                cnt_open++;
            } else {
                if (cnt_open) {
                    cnt_open--;
                } else {
                    cnt_left++;
                }
            }
        }

        int cnt_close = 0, cnt_right = 0;
        for (int i = len - 1; i >= 0; --i) {
            if (s[i] == ')') {
                cnt_close++;
            } else {
                if (cnt_close) {
                    cnt_close--;
                } else {
                    cnt_right++;
                }
            }
        }

        if (cnt_left && cnt_right) {
            continue;
        } else if (cnt_left) {
            tree_left[cnt_left]++;
        } else if (cnt_right) {
            tree_right[cnt_right]++;
        } else {
            cnt_ok++;
        }
    }

    int sol = cnt_ok / 2;
    for (it = tree_left.begin(); it != tree_left.end(); ++it) {
        sol += min(it->se, tree_right[it->fi]);
    }

    printf("%d\n", sol);

    return 0;
}
