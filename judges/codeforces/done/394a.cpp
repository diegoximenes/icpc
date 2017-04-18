#include<cstdio>
#include<cctype>
#include<cstring>
#include<cmath>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<bitset>
#include<map>
#include<queue>
#include<stack>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair
#define INF 1e9
#define MAX 105

int main()
{
	int a = 0, b = 0, c = 0;
	bool isa = 1, isb = 0;
	char cc;
	
	while(scanf("%c", &cc) == 1)
	{
		if(cc == '+') isb = 1, isa = 0;
		else if(cc == '=') isa = 0, isb = 0;
		else if(cc == '|')
		{
			if(isa) a++;
			else if(isb) b++;
			else ++c;
		}
	}
	
	if(a + b > c)
	{
		c++;
		if(a >= 2) a--;
		else b--;
	}
	else if(a + b < c)
	{
		a++;
		c--;
	}
	
	if(a == 0 || b == 0 || c == 0 || c != a+b)  puts("Impossible");
	else
	{
		for(int i=0; i<a; ++i) putchar('|');
		putchar('+');
		for(int i=0; i<b; ++i) putchar('|');
		putchar('=');
		for(int i=0; i<c; ++i) putchar('|');
		puts("");
	}

	return 0;
}
