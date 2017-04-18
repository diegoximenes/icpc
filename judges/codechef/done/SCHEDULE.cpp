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

char s[MAX];

bool check_1(int n, int k, int x) {
    int cnt_flips = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] - '0' != x)
            cnt_flips++;
        x = 1 - x;
    }
    return (cnt_flips <= k);
}

bool check(int max_len, int k, vector<int> &lens) {
    for (int i = 0; i < (int) lens.size(); ++i)
        k -= lens[i] / (max_len + 1);
    return (k >= 0);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d %d %s", &n, &k, s);

        vector<int> lens;
        int len = 1;
        for (int i = 1; i < n; ++i) {
            if (s[i] == s[i-1])
                len++;
            else {
                lens.pb(len);
                len = 1;
            }
        }
        lens.pb(len);

        int sol;
        if (check_1(n, k, 0) || check_1(n, k, 1))
            sol = 1;
        else {
            int l = 2, r = n;
            while (l <= r) {
                int mid = (l + r) / 2;

                if (check(mid, k, lens)) {
                    r = mid - 1;
                    sol = mid;
                } else {
                    l = mid + 1;
                }
            }
        }

        printf("%d\n", sol);
    }

    return 0;
}
