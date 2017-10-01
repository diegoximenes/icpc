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
    int n;
    string s;

    cin >> n >> s;
    int seattle_sf = 0, sf_seattle = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == 'S' && s[i + 1] == 'F') seattle_sf++;
        else if (s[i] == 'F' && s[i + 1] == 'S') sf_seattle++;
    }

    if (seattle_sf > sf_seattle) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
