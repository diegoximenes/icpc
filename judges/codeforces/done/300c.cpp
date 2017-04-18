#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

#define MOD 1000000007
#define ll long long

int isGood(ll n, ll a, ll b)
{
    ll d;
    int good = 1;

    /*if(n/10 == 0)
    {
        if(n == a || n == b)
            return 1;
        return 0;
    }*/

    //if(n == 0)
    //    return 0;

    while(n>0 && good)
    {
        d = n%10;
        n /= 10;
       // printf("n= %d\n", n);
        //sum += d;

        if(d != a && d != b)
            good = 0;
    }

   // printf("sumgood= %d\n",sum);

    if(!good)
        return 0;
    else
        return 1;

}

/*bool isExcelent(ll n, ll a, ll b)
{
    while(n > 0)
    {
        n = isGood(n, a, b);
        //printf("sum =%lld\n", sum);
    }
    
    if(n < 0)
        return false;
    else
        return true;
}*/

ll modinv(ll a, ll n)
{
    ll b = n, x = 0, lastx = 1, aux;
    while(b)
    {
        ll q = a/b, r = a%b;
        a = b; b = r;
        aux = x;
        x = lastx - q*x, lastx = aux;
    }
    while(lastx < 0)
        lastx += n;
    return lastx;
}

ll n, a, b;
ll fat[1000005];

int main()
{

    //scanf("%d %d %d", &n, &a, &b);
    cin >> a >> b >> n;

    fat[0] = 1;
    for(int i=1; i<=n; ++i)
    {
        fat[i] = i*fat[i-1]%MOD;
        //printf("fat i, %d, %lld\n", i, fat[i]);
    }

    ll count = 0;
    for(ll i=0; i<=n; ++i)
    {
        ll num  = i*a + (n-i)*b;
        //printf("num = %lld\n", num);  
        if(isGood(num, a, b))
        {
            count = (count +((fat[n]*modinv(fat[i], MOD))%MOD)*modinv(fat[n-i], MOD))%MOD;

            //printf("i= %lld, count= %lld\n", i, count);
        }
        //printf("i2= %lld\n", i);
    }
    
    //cout << count << endl;
    cout << count << endl;

    return 0;
}
