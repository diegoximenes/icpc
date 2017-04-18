#include<cstdio>
using namespace std;

int main()
{
	int n;
	long long int count = 0;
	
	scanf("%d", &n);
	for(int i=n; i>=0; --i)
		count += 3*i*(i+1)/2;
	printf("%I64d\n", count);
	//printf("%lld\n", count);
	
	return 0;
}