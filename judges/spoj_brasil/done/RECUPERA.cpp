#include<cstdio>
using namespace std;

int main()
{
	int n;

	for(int tc=1; scanf("%d", &n) == 1; ++tc)
	{
		int sum = 0, v;
		bool solved = 0;

		printf("Instancia %d\n", tc);
		for(int i=0; i<n; ++i)
		{
			scanf("%d", &v);
			if(!solved && v == sum) 
			{
				printf("%d\n\n", v);
				solved = 1;
			}
			sum += v;
		}
		if(!solved) puts("nao achei\n");
	}

	return 0;
}
