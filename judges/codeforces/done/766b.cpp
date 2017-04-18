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

int v[MAX], min_right[MAX];

int main()
{
    int n;

    scanf("%d", &n);
    for(int i=0; i<n; ++i)
        scanf("%d", &v[i]);

    sort(v, v + n);

    min_right[n - 2] = v[n - 1] - v[n - 2];
    for(int i=n - 3; i>=0; --i)
        min_right[i] = min(min_right[i + 1], v[i + 1] - v[i]);

    for(int i=0; i<=n-3; ++i)
        if(v[i] > min_right[i + 1])
        {
            puts("YES");
            return 0;
        }

    puts("NO");

    return 0;
}
