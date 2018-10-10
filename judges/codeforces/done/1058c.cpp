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

#define MAX 105

int n;
char s[MAX];

int main() {
    scanf("%d %s", &n, s);

    while (n - 1 >= 0 && s[n - 1] == '0') {
        n--;
    }
    if (n == 0) {
        puts("YES");
        return 0;
    }

    int sum = 0;
    for (int i = 0; i < n - 1; ++i) {
        sum += s[i] - '0';

        bool can = 1;
        int curr_sum = 0;
        for (int j = i + 1; j < n; ++j) {
            if (s[j] == '0') {
                continue;
            }

            curr_sum += s[j] - '0';
            if (curr_sum > sum) {
                can = 0;
            } else if (curr_sum == sum) {
                curr_sum = 0;
            }
        }

        if (curr_sum && curr_sum < sum) {
            can = 0;
        }

        if (can) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");

    return 0;
}
