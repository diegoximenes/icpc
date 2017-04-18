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

void read_v(int n, int &odd, int &even) {
    odd = even = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        if (i & 1)
            odd += x;
        else
            even += x;
    }
}

int main()
{
    int t;

    scanf("%d", &t);
    while (t--) {
        int n;
        int odd_1, even_1, odd_2, even_2;

        scanf("%d", &n);
        read_v(n, odd_1, even_1);
        read_v(n, odd_2, even_2);

        int sol = min(odd_1 + even_2, odd_2 + even_1);
        printf("%d\n", sol);
    }

    return 0;
}
