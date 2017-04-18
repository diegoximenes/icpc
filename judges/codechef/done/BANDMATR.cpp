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

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, cnt1 = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                int x;
                scanf("%d", &x);
                if (x)
                    cnt1++;
            }

        int sol = 0;
        cnt1 -= min(cnt1, n);
        for (int i = n - 1; (i >= 1) && (cnt1 > 0); --i) {
            cnt1 -= min(cnt1, 2 * i);
            sol++;
        }

        printf("%d\n", sol);
    }

    return 0;
}
