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

#define MAX 200005
#define LMAX 'z' - 'a' + 1

unordered_map<char, char> union_find_set;

void init() {
    for (char c = 'a'; c <= 'z'; ++c) {
        union_find_set[c] = c;
    }
}

char find(char c) {
    return union_find_set[c] = union_find_set[c] == c ?
        c :
        find(union_find_set[c]);
}

void merge(char c1, char c2) {
    if (c2 < c1) {
        swap(c1, c2);
    }
    union_find_set[find(c2)] = find(c1);
}

char s[MAX];

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d %d %s", &n, &k, s);

        init();
        for (int i = 0; i < n; ++i) {
            s[i] = find(s[i]);
            while ((k > 0) && (s[i] > 'a')) {
                k--;
                merge(s[i], s[i] - 1);
                s[i] = find(s[i]);
            }
        }

        printf("%s\n", s);
    }

    return 0;
}
