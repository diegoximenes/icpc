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

int main() {
    int n;

    int sol = 0;
    scanf("%d", &n);
    while (n--) {
        string s;
        cin >> s;
        if (s == "Tetrahedron")
            sol += 4;
        if (s == "Cube")
            sol += 6;
        if (s == "Octahedron")
            sol += 8;
        if (s == "Dodecahedron")
            sol += 12;
        if (s == "Icosahedron")
            sol += 20;
    }

    printf("%d\n", sol);

    return 0;
}
