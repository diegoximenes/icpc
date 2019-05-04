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

#define MAXL 6

vector<int> perms[MAXL];
int perms_size[] = {0, 24, 6, 2, 1};

string line;

int main() {
    /* ofstream outfile; */
    /* outfile.open("out"); */

    int t, f;
    getline(cin, line);
    sscanf(line.c_str(), "%d %d", &t, &f);
    /* outfile << t << ", " << f << endl; */
    /* outfile.flush(); */
    for (int tc = 1; tc <= t; ++tc) {
        set<char> added;
        string out;

        vector<int> targets;
        for (int i = 0; i < 119; ++i) {
            targets.pb(i);
        }

        for (int i = 1; i <= 4; ++i) {
            for (char c = 'A'; c <= 'E'; ++c) {
                perms[c - 'A'].clear();
            }
            for (int j = 0; j < (int) targets.size(); ++j) {
                cout << targets[j] * 5 + i << endl;
                cout.flush();
                /* outfile << targets[j] * 5 + i << endl; */
                /* outfile.flush(); */

                getline(cin, line);

                char r;
                sscanf(line.c_str(), "%c\n", &r);
                perms[r - 'A'].pb(targets[j]);
            }
            for (char c = 'A'; c <= 'E'; ++c) {
                if (added.find(c) == added.end() && (int) perms[c - 'A'].size() != perms_size[i]) {
                    added.insert(c);
                    out.pb(c);
                    targets.clear();
                    for (int j = 0; j < (int) perms[c - 'A'].size(); ++j) {
                        targets.pb(perms[c - 'A'][j]);
                    }
                    break;
                }
            }
        }

        for (char c = 'A'; c <= 'E'; ++c) {
            if (added.find(c) == added.end()) {
                out.pb(c);
                break;
            }
        }

        cout << out << endl;
        cout.flush();
        /* outfile << out << endl; */
        /* outfile.flush(); */
        char verdict;
        getline(cin, line);
        sscanf(line.c_str(), " %c ", &verdict);
        /* outfile << "verdict=" << verdict << endl; */
        /* outfile.flush(); */
    }

    return 0;
}
