#include<cstdio>
#include<cstring>
using namespace std;

#define ll long long
#define MAX (int) 1e5 + 100

int maxval;
ll tree[MAX], p;
ll bk[MAX], bk_1[MAX];
ll f[MAX];

ll read(int idx)
{
    ll sum = 0;
    while(idx > 0)
    {
        sum = (sum + tree[idx])%p;
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int idx, ll val)
{
    while(idx <= maxval)
    {
        tree[idx] = (tree[idx] + val)%p;
        idx += (idx & -idx);
    }
}

ll modinv(ll a, ll n) {
    ll b = n, x = 0, lastx = 1, aux;
    while(b)
    {
        ll q = a/b, r = a%b;
        a = b; b = r;
        aux = x;
        x = lastx- q*x; lastx  = aux;
    }
    while(lastx < 0)
        lastx += n;
    return lastx;
}

int main()
{
    ll b, l, n;
    ll sol;
    char op;

    while (scanf("%lld %lld %lld %lld", &b, &p, &l, &n), b)
    {
        maxval = l;
        bk[0] = bk_1[0] = 1;
        memset(tree, 0, sizeof(tree));
        for(int i=1; i<=maxval; ++i)
        {
            f[i] = 0;
            bk[i] = (bk[i-1] * b)%p;
            bk_1[i] = modinv(bk[i], p);
        }
        while(n--)
        {
            ll pos, j;

            scanf(" %c %lld %lld", &op, &pos, &j);
            ll v = l-pos+1, v2 = l-j+1;
            //printf("v= %lld, v2= %lld\n", v, v2);
            if(op == 'E') {
                update(v, bk[v-1]*j - bk[v-1]*f[pos]);
                //for(int i=1; i<=maxval; ++i)
                   //printf("%lld   ", tree[i]);
                //puts("");
                f[pos] = j;
            }
            else
            {
                sol = ((read(v) - read(v2-1))%p);
                if(sol < 0)
                    sol += p;
                //printf("sol= %lld\n", sol);
                sol = (sol*bk_1[v2-1])%p;
                printf("%lld\n", sol);
            }
        }
        puts("-");
    }

    return 0;
}
