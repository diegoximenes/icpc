#include<cstring>
#include<cstdio>
using namespace std;

#define MAX 50005

char s[MAX], left[MAX], right[MAX];

int main()
{
    int t;

    scanf("%d", &t);
    for(int tc=1; tc<=t; ++tc)
    {
        scanf(" %s ", s);

        int l = 0, r = strlen(s) - 1, sol = 0, cntl = 0;
        while(l < r)
        {
            left[cntl++] = s[l];
            right[cntl++] = s[r];
            
            bool can = 1;
            for(int i=0; i<cntl; ++i)
                if(left[i] != right[cntl-i-1])
                {
                    can = 0;
                    break;
                }

            if(can)
            {
                sol = sol + 1;
                cntl = 0;
            }

            ++l; --r;
        }
        
        sol *= 2;
        if(cntl || strlen(s)%2) sol++;

        printf("Case #%d: %d\n", tc, sol);
    }

    return 0;
}
