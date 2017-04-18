#include<bits/stdc++.h>
using namespace std;

#define PMAX 15

int pos[PMAX], trapped[PMAX];

int main()
{
    int p, s, t1, t2, t3, n, d1, d2;

    while(scanf("%d %d", &p, &s) && p)
    {
        memset(pos, 0, sizeof(pos));
        memset(trapped, 0, sizeof(trapped));
        scanf("%d %d %d %d", &t1, &t2, &t3, &n);
       
        int out, actualP = 0;
        bool solved = 0;
        for(int i=0; i<n; ++i)
        {   
            scanf("%d %d", &d1, &d2);
            
            while(trapped[actualP])
            {
                trapped[actualP] = 0;
                actualP = (actualP + 1)%p;
            }
                
            pos[actualP] += d1 + d2;
            
            
            if(!solved && pos[actualP] > s)
            {
                solved = 1;
                out = actualP + 1;
            }
            if(pos[actualP] == t1 || pos[actualP] == t2 || pos[actualP] == t3)
                trapped[actualP] = 1;

            //printf("i= %d, actualP= %d, pos= %d, trap= %d\n", i, actualP, pos[actualP], trapped[actualP]);
            actualP = (actualP + 1)%p;
        }

        printf("%d\n", out);
    }

    return 0;
}
