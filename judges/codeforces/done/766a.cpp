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

int main()
{
    string s1, s2;

    cin >> s1 >> s2;

    if(s1 == s2)
        puts("-1");
    else
        printf("%d\n", max((int)s1.size(), (int)s2.size()));

    return 0;
}
