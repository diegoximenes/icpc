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

#define MAX 1005
#define MOD 1000000007
#define MAXL ('z' - 'a' + 1)

int n, a[50];
int dp[MAX], dp2[MAX], max_len = -1, min_substr = INF;
char s[MAX];

int opt(int i)
{
    if(i == n)
        return 1;
    int &ret = dp[i];
    if(ret != -1)
        return ret;

    int curr_max_len = INF;

    ret = 0;
    for(int j=i; j<n; ++j)
    {
        curr_max_len = min(curr_max_len, a[s[j] - 'a']);
        if(j - i + 1 > curr_max_len)
            break;

        max_len = max(max_len, j - i + 1);
        ret = (ret + opt(j + 1)) % MOD;
    }

    return ret;
}

int opt2(int i)
{
    if(i == n)
        return 0;
    int &ret = dp2[i];
    if(ret != -1)
        return ret;

    int curr_max_len = INF;

    ret = INF;
    for(int j=i; j<n; ++j)
    {
        curr_max_len = min(curr_max_len, a[s[j] - 'a']);
        if(j - i + 1 > curr_max_len)
            break;

        max_len = max(max_len, j - i + 1);
        ret = min(ret, 1 + opt2(j + 1));
    }

    return ret;
}

int main()
{
    scanf("%d\n%s", &n, s);
    for(int i=0; i<26; ++i)
        scanf("%d", &a[i]);

    memset(dp, -1, sizeof(dp));
    memset(dp2, -1, sizeof(dp2));
    printf("%d\n%d\n%d\n", opt(0), max_len, opt2(0));

    return 0;
}
