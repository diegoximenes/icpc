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

int main() {
    ll n, q;
    cin >> n >> q;
    while (q--) {
        ll x, y;
        ll cnt;
        cin >> x >> y;

        cnt = 0;
        if (n % 2) {
            // odd
            if ((x + y) % 2) {
                cnt = ((n / 2) + (n % 2)) * ((n / 2) + (n % 2)) + ((n / 2) * (n / 2));
            }
            if ((x + y) % 2) {
                cnt += (((x - 1) / 2)) * ((n / 2) + (n % 2)) + (((x - 1) / 2) + ((x - 1) % 2)) * (n / 2);
            } else {
                cnt += (((x - 1) / 2) + ((x - 1) % 2)) * ((n / 2) + (n % 2)) + ((x - 1) / 2) * (n / 2);
            }
            cnt += (y / 2) + (y % 2);
        } else {
            // n even
            if ((x + y) % 2) {
                cnt = (n * n) / 2 + (n * n) % 2;
            }
            cnt += (x - 1) * (n / 2) + (y / 2) + (y % 2);
        }
        cout << cnt << endl;
    }

    return 0;
}
