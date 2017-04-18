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

#define MAX 55

string out[MAX];
bool effective[MAX];

int main() {
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n - k + 1; ++i) {
        string s;
        cin >> s;
        if (s == "YES")
            effective[i] = 1;
        else
            effective[i] = 0;
    }

    int id = 0;
    for (char c1 = 'A'; c1 <= 'Z'; ++c1)
        for (char c2 = 'a'; c2 <= 'z'; ++c2)
            if (id < n) {
                out[id] = "";
                out[id].pb(c1);
                out[id].pb(c2);
                id++;
            }

    int last_effective_right_pos = 0;
    for (int i = 0; i < n - k + 1; ++i) {
        if (effective[i] == 0) {
            int pos = i + 1;
            if (pos <= last_effective_right_pos)
                pos = last_effective_right_pos + 1;
            out[pos] = out[i];
        } else {
            last_effective_right_pos = i + k - 1;
        }
    }

    cout << out[0];
    for(int i = 1; i < n; ++i)
        cout << " " << out[i];
    cout << endl;

    return 0;
}
