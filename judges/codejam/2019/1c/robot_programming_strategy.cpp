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

#define MAX 505

string s[MAX];
bool won[MAX];

char will_loose(char c) {
    if (c == 'R') {
        return 'P';
    } else if (c == 'P') {
        return 'S';
    }
    return 'R';
}

int main() {
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> s[i];
        }
        memset(won, 0, sizeof(won));

        string out;
        bool can = 0;
        for (int i = 0; i < 500; ++i) {
            char curr_l = ' ';
            for (int j = 0; j < n; ++j) {
                if (!won[j]) {
                    curr_l = s[j][i % s[j].size()];
                    break;
                }
            }

            char target_l = will_loose(curr_l);
            int cnt_win = 0, cnt_tie = 0, cnt_loose = 0;
            for (int j = 0; j < n; ++j) {
                if (!won[j]) {
                    if (target_l == will_loose(s[j][i % s[j].size()])) {
                        cnt_win++;
                    } else if (target_l == s[j][i % s[j].size()]) {
                        cnt_tie++;
                    } else {
                        cnt_loose++;
                    }
                }
            }
            if (cnt_loose == 0) {
                if (cnt_tie == 0) {
                    can = 1;
                    out.push_back(target_l);
                    break;
                } else {
                    out.push_back(target_l);
                    for (int j = 0; j < n; ++j) {
                        if (!won[j]) {
                            if (target_l == will_loose(s[j][i % s[j].size()])) {
                                won[j] = 1;
                            }
                        }
                    }
                    continue;
                }
            }

            target_l = curr_l;
            cnt_win = 0, cnt_tie = 0, cnt_loose = 0;
            for (int j = 0; j < n; ++j) {
                if (!won[j]) {
                    if (target_l == will_loose(s[j][i % s[j].size()])) {
                        cnt_win++;
                    } else if (target_l == s[j][i % s[j].size()]) {
                        cnt_tie++;
                    } else {
                        cnt_loose++;
                    }
                }
            }
            if (cnt_loose == 0) {
                if (cnt_tie == 0) {
                    can = 1;
                    out.push_back(target_l);
                    break;
                } else {
                    out.push_back(target_l);
                    for (int j = 0; j < n; ++j) {
                        if (!won[j]) {
                            if (target_l == will_loose(s[j][i % s[j].size()])) {
                                won[j] = 1;
                            }
                        }
                    }
                    continue;
                }
            }

            break;
        }

        cout << "Case #" << tc << ": ";
        if (!can) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            cout << out << endl;
        }
    }

    return 0;
}
