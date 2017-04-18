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
    ll n, m, sol;
    cin >> n >> m;

    if (m >= n) {
        sol = n;
    } else {
        ll last = 0, l = 1, r = 2000000000LL;
        while (l <= r) {
            ll mid = (l + r) / 2;
            ll sum = (1LL + mid) * mid / 2;
            if (sum >= n - m) {
                last = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        sol = m + last;
    }

    cout << sol << endl;

    return 0;
}
