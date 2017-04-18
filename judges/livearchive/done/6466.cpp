#include<bits/stdc++.h>
using namespace std;

#define EPS 1e-7

int main()
{
    double a, b, f, sa, sb, sf, d;
    int t, n;

    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %lf %lf %lf %lf", &n, &d, &a, &b, &f);
        
        sa = 0; sb = d; sf = 0;
        double sol = 0;
        int turn = 1;
        while(1)
        {
            double t;

            if(turn) t = (sb - sf)/(b + f);
            else t = (sf - sa)/(a + f);
            
            //printf("t= %lf, sa= %lf, sb= %lf, sf= %lf\n", t, sa, sb, sf);

            if(t < 0.0 || fabs(t) <= EPS) break;

            sa = sa + a*t;
            sb = sb - b*t;
            
            double nsf;
            if(turn) nsf = sf + f*t;
            else nsf = sf - f*t;

            if(fabs(nsf - sf) <= 0.00001) break;
            
            sol += fabs(nsf - sf);
            sf = nsf;
            turn = 1 - turn;
        }

        printf("%d %.2lf\n", n, sol);
    }



    return 0;
}
