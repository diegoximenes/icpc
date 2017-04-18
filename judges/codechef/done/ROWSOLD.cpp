#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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

char s[MAX];
int cnt_one_right[MAX], cnt_empty_right[MAX];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf(" %s ", s);
        int n = strlen(s);

        cnt_one_right[n] = 0;
        for (int i = n - 1; i >= 0; --i) {
            cnt_one_right[i] = cnt_one_right[i + 1];
            if (s[i] == '1') cnt_one_right[i]++;
        }

        cnt_empty_right[n - 1] = 0;
        if (s[n - 1] == '0') cnt_empty_right[n - 1] = 1;
        for (int i = n - 2; i >= 0; --i) {
            cnt_empty_right[i] = cnt_empty_right[i + 1];
            if (s[i] == '0' && s[i + 1] == '1') cnt_empty_right[i]++;
        }

        ll sol = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == '1') {
                sol += (n - 1) - i - cnt_one_right[i + 1];
                sol += cnt_empty_right[i + 1];
            }
        }

        printf("%lld\n", sol);
    }

    return 0;
}
