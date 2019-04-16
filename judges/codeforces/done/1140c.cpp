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

#define MAX 300005
#define MAX2 1000005

int cnt_len[MAX2];
pair<int, int> songs[MAX];

int main() {
    int n, k;

    cin >> n >> k;
    memset(cnt_len, 0, sizeof(cnt_len));
    for (int i = 0; i < n; ++i) {
        cin >> songs[i].se >> songs[i].fi;
        cnt_len[songs[i].se]++;
    }
    sort(songs, songs + n);

    ll sum_len = 0;
    int i_len = MAX2 - 1;
    while (k) {
        if (cnt_len[i_len]) {
            sum_len += i_len;
            cnt_len[i_len]--;
            k--;
        } else {
            i_len--;
        }
    }

    ll sol = 0;
    for (int i = 0; i < n; ++i) {
        sol = max(sol, sum_len * songs[i].fi);
        if (songs[i].se >= i_len) {
            sum_len -= songs[i].se;
            while (i_len >= 1) {
                if (cnt_len[i_len]) {
                    sum_len += i_len;
                    cnt_len[i_len]--;
                    break;
                } else {
                    i_len--;
                }
            }
        } else {
            cnt_len[songs[i].se]--;
        }
    }

    cout << sol << endl;

    return 0;
}
