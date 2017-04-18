#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int n, k, count = 0;
	bool d[10];
	char a[20];

	scanf("%d %d", &n, &k);
	while(n--)
	{
		scanf(" %s", a);
		
		memset(d, 0, sizeof(d));
		int len = strlen(a), aux = 0;
		for(int i=0; i<len; ++i)
			if(a[i] - '0' <= k)
			{
				if(d[a[i] - '0'] == 0) ++aux; 
				d[a[i] - '0'] = 1;
			}

		if(aux == k + 1) count++;
	}
	printf("%d\n", count);

	return 0;
}
