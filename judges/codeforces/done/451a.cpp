#include<cstdio>
#include<cctype>
#include<cstring>
#include<cmath>
#include<string>
#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<set>
#include<bitset>
#include<map>
#include<queue>
#include<stack>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair
#define INF 1e9
#define EPS 1e-9

int main()
{
    int n, m;
    
    scanf("%d %d", &n, &m);
    
    int p = 0;
    while(n*m > 0) --n, --m,  p = 1 - p;
    
    if(p) puts("Akshat");
    else puts("Malvika");

    return 0;
}