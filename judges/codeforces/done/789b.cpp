#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL
const double PI = acos(-1);

ll mod(ll a) {
    if (a < 0)
        return -1LL * a;
    return a;
}

int main() {
    ll b, q, l;
    int m;
    set<ll> tree_a;

    cin >> b >> q >> l >> m;
    for (int i = 0; i < m; ++i) {
        ll x;
        cin >> x;
        tree_a.insert(x);
    }

    ll sol = 0;

    if (mod(b) > l) {
        cout << 0 << endl;
        return 0;
    }
    if (b == 0LL || q == 0LL) {
        if (tree_a.find(0LL) == tree_a.end())
            cout << "inf" << endl;
        else if (tree_a.find(b) == tree_a.end())
            cout << 1 << endl;
        else
            cout << 0 << endl;
        return 0;
    }
    if (q == 1LL) {
        if (tree_a.find(b) == tree_a.end())
            cout << "inf" << endl;
        else
            cout << 0 << endl;
        return 0;
    }
    if (q == -1LL) {
        if (tree_a.find(b) == tree_a.end() || tree_a.find(-b) == tree_a.end())
            cout << "inf" << endl;
        else
            cout << 0 << endl;
        return 0;
    }

    while (1) {
        if (mod(b) > l)
            break;

        if (tree_a.find(b) == tree_a.end())
            sol++;

        b *= q;
    }

    cout << sol << endl;

    return 0;
}
