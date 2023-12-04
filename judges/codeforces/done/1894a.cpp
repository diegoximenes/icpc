#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define pb push_back
#define mp make_pair
#define fi first
#define se second

#ifdef LOCAL
#define debug(...)                    \
    {                                 \
        fprintf(stderr, __VA_ARGS__); \
        fflush(stderr);               \
    }
#else
#define debug(...)
#endif

const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1);
const double EPS = 1e-9;

inline int cmp_double(double x, double y, double tol = EPS) {
    // (x < y): -1, (x == y): 0, (x > y): 1
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

template <class T>
inline void print_array(T *v, int n) {
    if (n > 0) {
        cout << v[0];
    }
    for (int i = 1; i < n; ++i) {
        cout << " " << v[i];
    }
    cout << endl;
}

template <class T>
inline void read_array(T *v, int n, int start = 0) {
    for (int i = start; i < start + n; ++i) {
        cin >> v[i];
    }
}

template <class T>
inline void print_vector(const vector<T> &v) {
    if (!v.empty()) {
        cout << v[0];
    }
    for (int i = 1; i < (int) v.size(); ++i) {
        cout << " " << v[i];
    }
    cout << endl;
}

template <class T>
inline void read_vector(vector<T> &v, int n, int start = 0) {
    for (int i = start; i < start + n; ++i) {
        cin >> v[i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        string s;
        cin >> n >> s;

        int wins_a = 0, wins_b = 0;
        for (int sets = 1; sets <= n; ++sets) {
            for (int wins_in_set = 1; wins_in_set <= n; ++wins_in_set) {
                int wins_in_set_a = 0, wins_in_set_b = 0, sets_win_a = 0,
                    sets_win_b = 0;
                for (int i = 0; i < n; ++i) {
                    if (s[i] == 'A') {
                        wins_in_set_a++;
                        if (wins_in_set_a == wins_in_set) {
                            wins_in_set_a = wins_in_set_b = 0;
                            sets_win_a++;
                        }
                    } else {
                        wins_in_set_b++;
                        if (wins_in_set_b == wins_in_set) {
                            wins_in_set_a = wins_in_set_b = 0;
                            sets_win_b++;
                        }
                    }

                    if (wins_in_set_a == 0 && wins_in_set_b == 0) {
                        if (sets_win_a == sets) {
                            if (i != n - 1) {
                                break;
                            }
                            wins_a++;
                        }
                        if (sets_win_b == sets) {
                            if (i != n - 1) {
                                break;
                            }
                            wins_b++;
                        }
                    }
                }
            }
        }
        if (wins_a && !wins_b) {
            cout << "A" << endl;
        } else if (!wins_a && wins_b) {
            cout << "B" << endl;
        } else {
            cout << "?" << endl;
        }
    }

    return 0;
}
