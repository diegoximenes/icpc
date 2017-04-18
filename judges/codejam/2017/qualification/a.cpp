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

#define MAX 1005

char s[MAX];

char inv(char c) {
    if (c == '+')
        return '-';
    return '+';
}

int main() {
    int t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; ++tc) {
        int k;
        scanf(" %s %d", s, &k);

        int n = strlen(s);
        int sol = 0;
        for (int i = 0; i < n - k + 1; ++i) {
            if (s[i] == '-') {
                for (int j = i; j < i + k; ++j)
                    s[j] = inv(s[j]);
                sol++;
            }
        }

        printf("Case #%d: ", tc);
        bool can = 1;
        for (int i = 0; i < n; ++i) {
            if (s[i] != '+') {
                can = 0;
            }
        }
        if (!can)
            puts("IMPOSSIBLE");
        else
            printf("%d\n", sol);
    }

    return 0;
}
