#include<bits/stdc++.h>
using namespace std;

#define MAX 20

int main()
{
    int t, n = 15, v[MAX], tc;
    
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &tc);
        for(int i=0; i<n; ++i) scanf("%d", &v[i]);
        
        int sol = 0;
        for(int i=1; i<n-1; ++i)
            for(int j=i; j<n-1; ++j)
            {
                bool can = 1;
                for(int k=i; can && k<=j; ++k)
                    if(v[k] <= v[i-1] || v[k] <= v[j+1])
                        can = 0;
                
                sol += can;
            }
        
        printf("%d %d\n", tc, sol);
    }

    return 0;
}
