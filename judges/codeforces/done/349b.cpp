#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

#define pb push_back
#define INF (int) 1e9

int main()
{
    int v, a[10], maxd = 0, minv = INF;
    vector<int> num;

    scanf("%d", &v);
    for(int i=0; i<9; ++i)
    {
        scanf("%d", &a[i]);
        maxd = max(maxd, v/a[i]);
        minv = min(minv, a[i]);
    }

    while(maxd > 0)
    {
        for(int i=8; i>=0; --i)
            if((v - a[i] >= 0) && (v-a[i])/minv == maxd-1)
            {
                num.pb(i+1);
                maxd--;
                v -= a[i];
                break;
            }
    }
    sort(num.begin(), num.end());
    for(int i=num.size()-1; i>=0; --i) printf("%d", num[i]);
    if(num.size() == 0) printf("-1");
    puts("");

    return 0;
}
