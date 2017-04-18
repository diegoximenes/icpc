#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define pb push_back

int main()
{
    int n, x, cnt1 = 0, cnt2 = 0, cnt3 = 0;

    scanf("%d", &n);
    for(int i=0; i<n; ++i)
    {
        scanf("%d", &x);
        if(x == 1) cnt1++;
        else if(x == 2) cnt2++;
        else if(x == 3) cnt3++;
    }

    bool no = 0;
    if(cnt1 == n || cnt2 == n || cnt3 == n) no = 1;
    if(n < 6)
    {
        vector<int> v;
        for(int i=0; i<cnt1; ++i) v.pb(0);
        for(int i=0; i<cnt2; ++i) v.pb(1);
        for(int i=0; i<cnt3; ++i) v.pb(2);

        int cntw = 0;
        do
        {
            ++cntw;
        }while(next_permutation(v.begin(), v.end()));

        if(cntw < 6) no = 1;
    }

    if(no) puts("No");
    else puts("Yes");

    return 0;
}