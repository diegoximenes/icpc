#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast_io ios::sync_with_stdio(false)
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

int main() {
    map<int, int> cnt;
    map<int, int>::iterator it;
    int n;
    scanf("%d", &n);
    while (n--) {
        int x;
        scanf("%d", &x);
        cnt[x]++;
    }
    for (it = cnt.begin(); it != cnt.end(); ++it) {
        if (it->se & 1) {
            puts("Conan");
            return 0;
        }
    }
    puts("Agasa");

    return 0;
}
