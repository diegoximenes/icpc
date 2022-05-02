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

#define MAX 40000 + 1
#define PMAX 500
const ll MODLL = 1000000007LL;

vector<int> palindromes;
ll dp[MAX][PMAX];

bool is_palindrome(int n) {
    vector<int> algarisms;
    while (n != 0) {
        algarisms.pb(n % 10);
        n /= 10;
    }
    int l = 0, r = algarisms.size() - 1;
    while (l < r) {
        if (algarisms[l] != algarisms[r]) {
            return false;
        }
        l++;
        r--;
    }
    return true;
}

int main() {
    for (int i = 1; i < MAX; ++i) {
        if (is_palindrome(i)) {
            palindromes.pb(i);
        }
    }

    for (int p = 0; p < (int) palindromes.size(); ++p) {
        dp[0][p] = 1;
    }
    for (int n = 1; n < MAX; ++n) {
        for (int p = 0; p < (int) palindromes.size(); ++p) {
            dp[n][p] = 0;
            if (n - palindromes[p] >= 0) {
                dp[n][p] = (dp[n][p] + dp[n - palindromes[p]][p]) % MODLL;
            }
            if (p > 0) {
                dp[n][p] = (dp[n][p] + dp[n][p - 1]) % MODLL;
            }
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << dp[n][(int) palindromes.size() - 1] << endl;
    }

    return 0;
}
