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

#define MAX 100005

char s[MAX];

int main() {
    ios::sync_with_stdio(false);

    map<char, int> c_id;
    c_id['C'] = 0;
    c_id['E'] = 1;
    c_id['S'] = 2;

    int t;
    scanf("%d", &t);
    while (t--) {
        scanf(" %s ", s);
        int n = strlen(s);
        int last = c_id[s[0]];
        bool can = 1;
        for (int i = 1; i < n; ++i) {
            if (c_id[s[i]] < last) can = 0;
            last = c_id[s[i]];
        }
        puts(can ? "yes" : "no");
    }

    return 0;
}
