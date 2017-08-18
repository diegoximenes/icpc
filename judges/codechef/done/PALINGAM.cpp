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

char s1[MAX], s2[MAX];

map<char, int> cnt_letters(char *s, int n) {
    map<char, int> ret;
    for (int i = 0; i < n; ++i) ret[s[i]]++;
    return ret;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        char sol;
        bool solved = 0;
        scanf(" %s %s ", s1, s2);
        int n = strlen(s1);

        map<char, int> cnt1 = cnt_letters(s1, n);
        map<char, int> cnt2 = cnt_letters(s2, n);
        map<char, int>::iterator it;

        for (it = cnt1.begin(); it != cnt1.end(); ++it) {
            if (it->se >= 2 && cnt2.find(it->fi) == cnt2.end()) {
                sol = 'A';
                solved = 1;
                break;
            }
        }

        if (!solved) {
            bool can = 0;
            for (it = cnt1.begin(); it != cnt1.end(); ++it) {
                if (cnt2.find(it->fi) == cnt2.end()) {
                    cnt1[it->fi]--;
                    if (cnt1[it->fi] == 0) cnt1.erase(it->fi);
                    can = 1;
                    break;
                }
            }
            if (!can) {
                solved = 1;
                sol = 'B';
            }

            if (!solved) {
                for (it = cnt2.begin(); it != cnt2.end(); ++it) {
                    if (cnt1.find(it->fi) == cnt1.end()) {
                        sol = 'B';
                        solved = 1;
                        break;
                    }
                }
                if (!solved) {
                    sol = 'A';
                    solved = 1;
                }
            }
        }

        printf("%c\n", sol);
    }

    return 0;
}
