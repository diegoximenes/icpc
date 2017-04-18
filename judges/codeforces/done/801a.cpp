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
const double EPS = 1e-9;

inline int cmp_double(double x, double y, double tol = EPS) {
    // (x < y): -1, (x == y): 0, (x > y): 1
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

#define MAX 105

int n;
char s[MAX];

int calc() {
    int sol = 0;
    for (int i = 0; i < n - 1; ++i)  {
        if (s[i] == 'V' && s[i + 1] == 'K')
            sol++;
    }
    return sol;
}

int main() {
    scanf(" %s ", s);
    n = strlen(s);

    int sol = calc();
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'V')
            s[i] = 'K';
        else
            s[i] = 'V';

        sol = max(sol, calc());

        if (s[i] == 'V')
            s[i] = 'K';
        else
            s[i] = 'V';
    }

    printf("%d\n", sol);

    return 0;
}
