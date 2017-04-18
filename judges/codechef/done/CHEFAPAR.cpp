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

int main()
{
    int t;

    scanf("%d", &t);
    while(t--)
    {
        int n, x, sol = 0;
        bool late = 0;

        scanf("%d", &n);
        for(int i=0; i<n; ++i)
        {
            scanf("%d", &x);
            if(!x)
            {
                late = 1;
                sol += 1000;
            }
            if(late)
                sol += 100;
        }
        printf("%d\n", sol);
    }

    return 0;
}
