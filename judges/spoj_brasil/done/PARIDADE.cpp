#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int n, count = 0, lastbit;
	bool bit[32];

	while(scanf("%d", &n) && n)
	{
		memset(bit, 0, sizeof(bit));
		count = 0;
		for(int i=0; i<32; ++i)
			if(n & (1 << i))
			{
				bit[i] = 1;
				++count;
				lastbit = i;
			}
		
		printf("The parity of ");
		for(int i=lastbit; i>=0; --i)
			printf("%d", bit[i]);
		printf(" is %d (mod 2).\n", count);
	}

	return 0;
}
