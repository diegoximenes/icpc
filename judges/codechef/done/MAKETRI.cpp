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

#define MAX 1000005

int n;
ll v[MAX], l, r;

int main()
{
    cin >> n >> l >> r;
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    sort(v, v + n);
    vector< pair<ll, ll> > intervals;
    for (int i = 1; i < n; ++i) {
        ll int_l = max(l, v[i] - v[i - 1] + 1);
        ll int_r = min(r, v[i - 1] + v[i] - 1);

        if (int_r >= int_l)
            intervals.pb(mp(int_l, int_r));
    }

    ll sol = 0;
    if (!intervals.empty()) {
        sort(intervals.begin(), intervals.end());
        ll curr_l = intervals[0].fi, curr_r = intervals[0].se;
        for (int i = 1; i < (int)intervals.size(); ++i) {
            if (intervals[i].fi > curr_r) {
                sol += curr_r - curr_l + 1;
                curr_l = intervals[i].fi;
            }
            curr_r = max(curr_r, intervals[i].se);
        }
        sol += curr_r - curr_l + 1;
    }

    cout << sol << endl;

    return 0;
}
