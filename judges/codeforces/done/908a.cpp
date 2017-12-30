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
    string s;
    cin >> s;
    set<char> tree;
    tree.insert('a');
    tree.insert('e');
    tree.insert('i');
    tree.insert('o');
    tree.insert('u');
    tree.insert('1');
    tree.insert('3');
    tree.insert('5');
    tree.insert('7');
    tree.insert('9');
    int n = s.size();
    int sol = 0;
    for (int i = 0; i < n; ++i) {
        if (tree.find(s[i]) != tree.end()) {
            sol++;
        }
    }
    printf("%d\n", sol);

    return 0;
}
