#include<cstdio>
using namespace std;

long long int expo(long long int x, int a)
{
	long long int temp;
	if(a == 0)
		return 1;
	if(a == 1)
		return x;
	temp = expo(x*x, a/2);
	if(a%2 == 0)
		return temp;
	return x*temp;
}

int main()
{
	int a, b, c;
	
	scanf("%d %d %d", &a, &b, &c);
	printf("%I64d\n%I64d\n2\n", expo(2, (c-1)/a), expo(2, (c-1)/b));
	
	return 0;
}
