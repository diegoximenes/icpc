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

int v[MAX], sum[2 * MAX];

int main()
{
    int t;

    scanf("%d", &t);
    while (t--) {
        int o1, o2;
        scanf("%d %d", &o1, &o2);
        int n = o1 * o2;
        for (int i = 1; i <= n; ++i)
            scanf("%d", &v[i]);

        sum[0] = 0;
        for (int i = 0; i < 2 * n; ++i)
            sum[i + 1] = v[i % n + 1] + sum[i];

        bool can = 0;
        for (int i = 0; i < o2; ++i) {
            int cnt = 0;
            for (int j = 0; j < o1; ++j) {
                int l = 1 + j * o2 + i;
                int r = l + o2 - 1;

                if (sum[r] - sum[l - 1] > o2 / 2)
                    cnt++;
            }
            if (cnt > o1 / 2)
                can = 1;
        }
        puts(can ? "1" : "0");
    }

    return 0;
}
