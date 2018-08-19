#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast_io ios::sync_with_stdio(false)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1);
const double EPS = 1e-9;

inline int cmp_double(double x, double y, double tol = EPS) {
    // (x < y): -1, (x == y): 0, (x > y): 1
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

void myreverse(string &s, int l, int r) {
    while (l < r) {
        swap(s[l], s[r]);
        l++;
        r--;
    }
}

int solve(string s) {
    int n = s.size();
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i - 1]) {
            if (s[0] != s[n - 1]) {
                myreverse(s, 0, i - 1);
                myreverse(s, i, n - 1);
            }
            break;
        }
    }

    int sol = 1;
    int lsol = 1;
    for (int i = 1; i < n; ++i) {
        if (s[i] != s[i - 1]) {
            lsol++;
        } else {
            lsol = 1;
        }
        sol = max(lsol, sol);
    }
    return sol;
}

int main() {
    string s;
    cin >> s;

    int sol = solve(s);
    myreverse(s, 0, s.size() - 1);
    sol = max(sol, solve(s));
    cout << sol << endl;

    return 0;
}
