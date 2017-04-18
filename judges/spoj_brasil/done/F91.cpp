#include<cstdio>
using namespace std;

int f(int n)
{
	if(n >= 101) return n - 10;
	return f(f(n + 11));
}

int main()
{
	int n;

	while(scanf("%d", &n) && n)
		printf("f91(%d) = %d\n", n, f(n));
	
	return 0;
}
