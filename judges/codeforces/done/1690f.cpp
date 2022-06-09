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

#define MAX 201

int p[MAX], p_odd[MAX], p_even[MAX];
char s_odd[MAX], s_even[MAX];
bool mark[MAX];

ll gcd(ll a, ll b) {
    return (b == 0 ? a : gcd(b, a % b));
}
ll lcm(ll a, ll b) {
    return a * (b / gcd(a, b));
}

int main() {
    fast_io;
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
            p[i]--;
            mark[i] = 0;
        }

        vector<int> cycles_lengths;
        for (int i = 0; i < n; ++i) {
            if (!mark[i]) {
                vector<int> cycle;
                cycle.pb(i);

                for (int j = 0; j < n; ++j) {
                    p_even[j] = p[j];
                }
                for (int it = 1; ; it++) {
                    if (it & 1) {
                        for (int j = 0; j < n; ++j) {
                            p_odd[j] = p_even[p[j]];
                        }
                        if (p_odd[i] == i) {
                            break;
                        }
                        cycle.pb(p_odd[i]);
                        mark[p_odd[i]] = 1;
                    } else {
                        for (int j = 0; j < n; ++j) {
                            p_even[j] = p_odd[p[j]];
                        }
                        if (p_even[i] == i) {
                            break;
                        }
                        cycle.pb(p_even[i]);
                        mark[p_even[i]] = 1;
                    }
                }

                for (int j = 0; j < n; ++j) {
                    s_even[j] = s[j];
                }
                for (int it = 1; ; it++) {
                    if (it & 1) {
                        for (int j = 0; j < n; ++j) {
                            s_odd[j] = s_even[p[j]];
                        }

                        bool can = 1;
                        for (int j = 0; j < (int) cycle.size(); ++j) {
                            if (s[cycle[j]] != s_odd[cycle[j]]) {
                                can = 0;
                            }
                        }
                        if (can) {
                            cycles_lengths.pb(it);
                            break;
                        }
                    } else {
                        for (int j = 0; j < n; ++j) {
                            s_even[j] = s_odd[p[j]];
                        }

                        bool can = 1;
                        for (int j = 0; j < (int) cycle.size(); ++j) {
                            if (s[cycle[j]] != s_even[cycle[j]]) {
                                can = 0;
                            }
                        }
                        if (can) {
                            cycles_lengths.pb(it);
                            break;
                        }
                    }
                }
            }
        }

        ll out = 1;
        for (int i = 0; i < (int) cycles_lengths.size(); ++i) {
            out = lcm(out, cycles_lengths[i]);
        }
        cout << out << endl;
    }

    return 0;
}
