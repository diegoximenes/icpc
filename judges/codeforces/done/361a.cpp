#include<cstdio>
using namespace std;

int main()
{
	int n, k;

	scanf("%d %d", &n, &k);
	for(int i=0; i<n; ++i, puts(""))
		for(int j=0; j<n; ++j)
		{
			if(i == j) printf("%d", k);
			else putchar('0');
			if(j != n-1) putchar(' ');
		}

	return 0;
}
