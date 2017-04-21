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

#define MAX 20

char s[MAX];

int main() {
    scanf(" %s ", s);

    int i = 0, j = strlen(s) - 1;
    int cnt = 0;
    while (i < j) {
        if (s[i] != s[j]) cnt++;
        i++; j--;
    }

    bool can = 0;
    int n = strlen(s);
    if (cnt == 1 || (cnt == 0 && n % 2 == 1)) can = 1;
    puts(can ? "YES" : "NO");

    return 0;
}
