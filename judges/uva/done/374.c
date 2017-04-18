#include<stdio.h>

long long unsigned expo(long long unsigned a, long long unsigned b, long long unsigned c)
{
    long long temp;
    
    if(b == 0) return 1;
    
    temp = expo(a, b/2, c);
    
    if(b%2) return (temp*temp*a)%c;
    else return (temp*temp)%c;
}

int main()
{
    long long b, p, m;
    while(scanf("%lld %lld %lld", &b, &p, &m) == 3)
    {
	printf("%lld\n", expo(b,p,m));
    }
    
    return 0;
}