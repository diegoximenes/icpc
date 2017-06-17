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

vector<int> get_v(int x) {
    vector<int> ret;
    ret.pb(x % 10);
    x /= 10;
    ret.pb(x % 10);
    return ret;
}

bool is_palindrome(int h, int m, int i) {
    int time = (h * 60 + m + i) % (24 * 60);
    int hour = time / 60;
    int min =  time % 60;

    vector<int> vh = get_v(hour), vm = get_v(min);
    if (vh[0] == vm[1] && vh[1] == vm[0]) {
        return 1;
    }
    return 0;
}

int main() {
    int h, m;

    scanf("%d:%d", &h, &m);
    for (int i = 0; i < 24 * 60; ++i) {
        if (is_palindrome(h, m, i)) {
            printf("%d\n", i);
            return 0;
        }
    }

    return 0;
}
