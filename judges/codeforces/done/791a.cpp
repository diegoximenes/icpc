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

int main() {
    int a, b;

    scanf("%d %d", &a, &b);
    int sol = 0;
    while (a <= b) {
        a *= 3;
        b *= 2;
        sol++;
    }

    printf("%d\n", sol);

    return 0;
}
