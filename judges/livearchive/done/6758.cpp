#include<cstdio>
using namespace std;

int main()
{
    int n, x, y, t;
    
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d %d", &n, &x, &y);
        bool easy = 0, hard = 0;
        for(int i=0; i<n; ++i)
        {
            int aux;
            scanf("%d", &aux);
            if(i == 0 && aux == x) easy = 1;
            else if(i == n-1 && aux == y) hard = 1;
        }

        if(hard && easy) puts("BOTH");
        else if(!hard && !easy) puts("OKAY");
        else if(hard) puts("HARD");
        else if(easy) puts("EASY");
    }

    return 0;
}
