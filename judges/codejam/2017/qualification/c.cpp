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

pair<ll, ll> get_next(ll x) {
    if (x & 1LL) return mp(x / 2LL, x / 2LL);
    return mp(x / 2LL, max(0LL, x / 2LL - 1));
}

void update(ll next, ll cnt, ll new_x1, ll &new_cnt1, ll &new_x2,
            ll &new_cnt2) {
    if (cnt == 0) return;
    if (next == new_x1) {
        new_cnt1 += cnt;
    } else {
        new_x2 = next;
        new_cnt2 += cnt;
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; ++tc) {
        ll n, k;
        scanf("%lld %lld", &n, &k);

        ll x1 = n, cnt1 = 1, x2 = 0, cnt2 = 0;
        pair<ll, ll> p_sol;
        while (1) {
            pair<ll, ll> p1 = get_next(x1);
            k -= cnt1;
            if (k <= 0) {
                p_sol = p1;
                break;
            }

            pair<ll, ll> p2 = get_next(x2);
            k -= cnt2;
            if (k <= 0) {
                p_sol = p2;
                break;
            }

            // printf("x1=%lld, cnt1=%lld, x2=%lld, cnt2=%lld, k=%lld\n",
            //        x1, cnt1, x2, cnt2, k);

            ll new_x1 = 0, new_cnt1 = 0, new_x2 = 0, new_cnt2 = 0;

            new_x1 = p1.fi;
            new_cnt1 = cnt1;
            if (x1 > 2LL)
                update(p1.se, cnt1, new_x1, new_cnt1, new_x2, new_cnt2);
            update(p2.fi, cnt2, new_x1, new_cnt1, new_x2, new_cnt2);
            if (x2 > 2LL)
                update(p2.se, cnt2, new_x1, new_cnt1, new_x2, new_cnt2);

            x1 = new_x1; cnt1 = new_cnt1;
            x2 = new_x2; cnt2 = new_cnt2;
        }

        printf("Case #%d: ", tc);
        printf("%lld %lld\n", p_sol.fi, p_sol.se);
    }

    return 0;
}
