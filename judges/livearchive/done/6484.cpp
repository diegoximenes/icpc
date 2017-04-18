#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

#define pb push_back
#define MAX 1005

char s[MAX];
bool have[MAX];

int main()
{
    while(scanf(" %s ", s) && strcmp(s, "0") != 0)
    {
        int n = strlen(s);
        vector<int> out;
        memset(have, 0, sizeof(have));
        for(int i=1; i<n; ++i)
        {
            int cnt = 0;
            for(int j=1; j<i; ++j)
                if(have[j] && i%j == 0)
                    ++cnt;
            
            if(s[i] == '0' && cnt%2 == 1) out.pb(i), have[i] = 1;
            else if(s[i] == '1' && cnt%2 == 0) out.pb(i), have[i] = 1;
        }

        printf("%d", out[0]);
        for(int i=1; i<(int)out.size(); ++i) printf(" %d", out[i]);
        puts("");

    }

    return 0;
}
