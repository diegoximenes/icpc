#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int n, m;

	while(scanf("%d %d", &n, &m) == 2)
	{
		int cnt = 0;
		for(int i=n; i<=m; ++i)
		{
			bool dig[10];
			memset(dig, 0, sizeof(dig));
			int aux = i;
			bool can = 1;
			while(can && aux != 0)
			{
				if(dig[aux%10] != 0) can = 0;
				else dig[aux%10] = 1;
				aux /= 10;
			}
			if(can) ++cnt;
		}
		printf("%d\n", cnt);
	}

	return 0;
}
