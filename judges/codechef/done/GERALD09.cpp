#include<cstdio>
#include<ctime>
#include<cstdlib>
using namespace std;

int main()
{
	int t, n, m, k;

	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d %d", &n, &m, &k);
		srand(time(NULL));
		for(int i=0; i<n; ++i, puts(""))
			for(int j=0; j<m; ++j)
			{
				int x = rand()%4;
				if(x == 0) putchar('G');
				else if(x == 1) putchar('C');
				else if(x == 2) putchar('A');
				else putchar('T');
			}
	}

	return 0;
}
