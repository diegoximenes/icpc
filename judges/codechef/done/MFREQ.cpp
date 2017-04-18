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

#define MAX 100005

int n, q, v[MAX], cnt_left[MAX], cnt_right[MAX];

int check(int l, int r, int k) {
    int mid = (l + r) / 2;
    int cnt = min(mid - l + 1, cnt_left[mid]) +
        min(r - mid + 1, cnt_right[mid]) - 1;
    if(cnt >= k)
        return v[mid];
    return -1;
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; ++i)
        scanf("%d", &v[i]);

    cnt_left[0] = 1;
    for (int i = 1; i < n; ++i) {
        if (v[i] == v[i - 1])
            cnt_left[i] = cnt_left[i - 1] + 1;
        else
            cnt_left[i] = 1;
    }
    cnt_right[n - 1] = 1;
    for (int i = n - 2; i >= 0; --i) {
        if (v[i] == v[i + 1])
            cnt_right[i] = cnt_right[i + 1] + 1;
        else
            cnt_right[i] = 1;
    }

    while(q--) {
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        --l; --r;

        int mid = (l + r) / 2;
        if (check(l, r, k) != -1)
            printf("%d\n", check(l, r, k));
        else if (check(l, mid, k) != -1)
            printf("%d\n", check(l, mid, k));
        else if (check(mid, r, k) != -1)
            printf("%d\n", check(mid, r, k));
        else
            puts("-1");
    }


    return 0;
}
