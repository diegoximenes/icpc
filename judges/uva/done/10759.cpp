#include<cstdio>
#include<cassert>
using namespace std;

#define MAXSUM 24*6 + 10
#define MAX 24+10

struct Division
{
	long long int n, d;
	Division(long long int n = 0, long long int d = 1): n(n), d(d) {}
};

long long int gcd(long long int a, long long int b)
{
	return (b == 0 ? a : gcd(b, a%b));
}

long long int lcm(long long int a, long long int b)
{
	return (a*(b/gcd(a, b)));
}

Division sumDivision(Division a, Division b)
{
	Division c;
	long long int l = lcm(a.d, b.d), g;
	c.n = a.n*(l/a.d) + b.n*(l/b.d);
	c.d = l;
	
	g = gcd(c.n, c.d);
	c.n /= g; c.d /= g;
	
	return c;
}

Division mulDivision(Division a, Division b)
{
	Division c;
	long long int g1 = gcd(a.n, b.d), g2 = gcd(a.d, b.n);
	a.n /= g1; b.d /= g1;
	a.d /= g2; b.n /= g2;
	
	c.n = a.n*b.n;
	c.d = a.d*b.d;
	
	//g1 = gcd(c.n, c.d);
	//c.n /= g1; c.d /= g1;
	
	return c;
}

int main()
{
	int n = 24, x;
	Division p[MAX][MAXSUM];
	
	for(int i=1; i<=6; ++i)
	{
		p[1][i].n = 1;
		p[1][i].d = 6;
	}
	for(int i=2; i<=n; ++i)
	{
		for(int j=i; j<=i*6; ++j)
		{
			p[i][j].n = 0;
			p[i][j].d = 1;
			for(int k=i-1; k<=(i-1)*6; ++k)
				if(j-k <= 6)
				{
					Division paux;
					paux = mulDivision(p[i-1][k], p[1][j-k]);
					
					p[i][j] = sumDivision(p[i][j], paux);
				}
		}
	}
	
	while(scanf("%d %d", &n, &x) && n)
	{	
		Division prob = p[n][x];
		for(int i=x+1; i<=6*n; ++i)
			prob = sumDivision(prob, p[n][i]);
		
		if(prob.n == 0)
			puts("0");
		else if((prob.n == 1) && (prob.d == 1))
			puts("1");
		else
			printf("%lld/%lld\n", prob.n, prob.d);
	}
	
	return 0;
}