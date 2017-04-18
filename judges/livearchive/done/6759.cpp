#include<cstdio>
#include<cstring>
using namespace std;

#define MAX 100005

char s[MAX];

int main()
{
    int t;

    scanf("%d", &t);
    while(t--)
    {
        scanf(" %s ", s);
        int n = strlen(s), r = 0, l = 0, u = 0, d = 0, aux = 0;
    
        for(int i=0; i<n; ++i)
        {
            if(s[i] == 'R') ++r;
            else if(s[i] == 'L') ++l;
            else if(s[i] == 'U') ++u;
            else if(s[i] == 'D') ++d;
            else aux++;
        }

        int x = r - l, y = u - d;
        int minx = x - aux, miny = y - aux, maxx = x + aux, maxy = y + aux;

        printf("%d %d %d %d\n", minx, miny, maxx, maxy);
    }

    return 0;
}
