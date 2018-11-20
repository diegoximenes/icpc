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

int dp[6][MAX], a[MAX], n;

int opt(int last_finger, int i) {
    if (i == n) {
        return 1;
    }
    int &ret = dp[last_finger][i];
    if (ret != -1) {
        return ret;
    }

    ret = 0;
    if (a[i - 1] < a[i]) {
        for (int finger = last_finger + 1; finger < 5; finger++) {
            ret = ret || opt(finger, i + 1);
        }
    } else if (a[i - 1] > a[i]) {
        for (int finger = 0; finger < last_finger; finger++) {
            ret = ret || opt(finger, i + 1);
        }
    } else {
        for (int finger = 0; finger < 5; finger++) {
            if (finger != last_finger) {
                ret = ret || opt(finger, i + 1);
            }
        }
    }

    return ret;
}

void build(int last_finger, int i) {
    if (i == n) {
        return;
    }

    if (a[i - 1] < a[i]) {
        for (int finger = last_finger + 1; finger < 5; finger++) {
            if (opt(last_finger, i) == opt(finger, i + 1)) {
                printf(" %d", finger + 1);
                build(finger, i + 1);
                return;
            }
        }
    } else if (a[i - 1] > a[i]) {
        for (int finger = 0; finger < last_finger; finger++) {
            if (opt(last_finger, i) == opt(finger, i + 1)) {
                printf(" %d", finger + 1);
                build(finger, i + 1);
                return;
            }
        }
    } else {
        for (int finger = 0; finger < 5; finger++) {
            if (finger != last_finger) {
                if (opt(last_finger, i) == opt(finger, i + 1)) {
                    printf(" %d", finger + 1);
                    build(finger, i + 1);
                    return;
                }
            }
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    memset(dp, -1, sizeof(dp));
    int finger, sol = 0;
    for (finger = 0; finger < 5; ++finger) {
        sol = opt(finger, 1);
        if (sol) {
            break;
        }
    }
    if (!sol) {
        puts("-1");
    } else {
        printf("%d", finger + 1);
        build(finger, 1);
        puts("");
    }

    return 0;
}
