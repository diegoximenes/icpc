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
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();

    cout << s1[0];
    for (int i = 1; i < n && s1[i] < s2[0]; ++i) {
        cout << s1[i];
    }
    cout << s2[0] << endl;

    return 0;
}
