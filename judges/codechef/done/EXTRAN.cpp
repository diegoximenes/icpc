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

int v[MAX];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &v[i]);

        int sol;
        sort(v, v + n);
        if (v[0] + 1 < v[1])
            sol = v[0];
        else if (v[n - 1] - 1 > v[n - 2])
            sol = v[n - 1];
        else {
            for (int i = 1; i < n; ++i)
                if (v[i] == v[i - 1]) {
                    sol = v[i];
                    break;
                }
        }

        printf("%d\n", sol);
    }

    return 0;
}
