#include<set>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;

typedef long long ll;
const ll maxFirst = 1000000;
#define MAX 1000005

ll gcd(ll a, ll b) { return (b == 0 ? a : gcd(b, a%b)); }
ll lcm(ll a, ll b) { return (a * (b / gcd(a, b))); }

bool mark[MAX];

int main()
{
    int t;
    ll n1, f1, d1, n2, f2, d2;

    scanf("%d", &t);
    while(t--)
    {
        cin >> n1 >> f1 >> d1 >> n2 >> f2 >> d2;
        
        memset(mark, 0, sizeof(mark));
        ll x1 = f1, x2 = f2, first;
        while(x1 <= maxFirst)
        {
            mark[x1] = 1;
            x1 += d1;
        }
        while(x2 <= maxFirst)
        {
            if(mark[x2])
            {
                first = x2;
                break;
            }
            x2 += d2;
        }
       
        ll p1 = lcm(d1, d2)/d1, p2 = lcm(d1, d2)/d2;
        ll sol1 = (n1 - (first-f1)/d1 + p1-1)/p1;
        ll sol2 = (n2 - (first-f2)/d2 + p2-1)/p2;

        ll sol = max(0LL, min(sol1, sol2));
        cout << sol << endl;
    }

    return 0;
}
