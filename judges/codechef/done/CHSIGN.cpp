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

int a[MAX], n;
ll dp[MAX][2][2];
bool calc_dp[MAX][2][2];

ll opt(int i, bool neg1, bool neg2) {
    if (i == n) {
        return 0;
    }
    ll &ret = dp[i][neg1][neg2];
    if (calc_dp[i][neg1][neg2]) {
        return ret;
    }

    ll last1, last2;
    if (i >= 1) {
        last1 = a[i - 1];
        if (neg1) {
            last1 *= -1;
        }
    }
    if (i >= 2) {
        last2 = a[i - 2];
        if (neg2) {
            last2 *= -1;
        }
    }

    ret = INFLL;
    if (i == 0) {
        ret = min(ret, a[i] + opt(i + 1, 0, 0));
        ret = min(ret, - a[i] + opt(i + 1, 1, 0));
    } else if (i == 1) {
        if (a[i] + last1 > 0) {
            ret = min(ret, a[i] + opt(i + 1, 0, neg1));
        }
        if (- a[i] + last1 > 0) {
            ret = min(ret, - a[i] + opt(i + 1, 1, neg1));
        }
    } else {
        if ((a[i] + last1 > 0) && (a[i] + last1 + last2 > 0)) {
            ret = min(ret, a[i] + opt(i + 1, 0, neg1));
        }
        if ((- a[i] + last1 > 0) && (- a[i] + last1 + last2 > 0)) {
            ret = min(ret, - a[i] + opt(i + 1, 1, neg1));
        }
    }

    calc_dp[i][neg1][neg2] = 1;
    return ret;
}

void build(int i, bool neg1, bool neg2) {
    if (i == n) {
        puts("");
        return;
    }
    ll ret = opt(i, neg1, neg2);

    ll last1, last2;
    if (i >= 1) {
        last1 = a[i - 1];
        if (neg1) {
            last1 *= -1;
        }
    }
    if (i >= 2) {
        last2 = a[i - 2];
        if (neg2) {
            last2 *= -1;
        }
    }

    if (i == 0) {
        if (ret == a[i] + opt(i + 1, 0, 0)) {
            printf("%d", a[i]);
            build(i + 1, 0, 0);
        } else {
            printf("%d", - a[i]);
            build(i + 1, 1, 0);
        }
    } else if (i == 1) {
        if ((a[i] + last1 > 0) && (ret == a[i] + opt(i + 1, 0, neg1))) {
            printf(" %d", a[i]);
            build(i + 1, 0, neg1);
            return;
        }
        if ((- a[i] + last1 > 0) && (ret == - a[i] + opt(i + 1, 1, neg1))) {
            printf(" %d", -a[i]);
            build(i + 1, 1, neg1);
        }
    } else {
        if ((a[i] + last1 > 0) && (a[i] + last1 + last2 > 0) &&
            (ret == a[i] + opt(i + 1, 0, neg1))) {
            printf(" %d", a[i]);
            build(i + 1, 0, neg1);
            return;
        }
        if ((- a[i] + last1 > 0) && (- a[i] + last1 + last2 > 0) &&
            (ret == - a[i] + opt(i + 1, 1, neg1))) {
            printf(" %d", -a[i]);
            build(i + 1, 1, neg1);
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }

        memset(calc_dp, 0, sizeof(calc_dp));
        build(0, 0, 0);
    }

    return 0;
}
