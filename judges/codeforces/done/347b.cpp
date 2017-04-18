#include<cstdio>
using namespace std;

#define MAX 100010

int main()
{
	int n, v[MAX], count = 0, aux = 0;
	bool canSwap[MAX];

	scanf("%d", &n);	
	for(int i=0; i<n; ++i)
	{
		scanf("%d", &v[i]);
		if(v[i] == i)
		{
			++count;
			canSwap[i] = 0;
		}
		else canSwap[v[i]] = 1;
	}

	for(int i=0; i<n; ++i)
	{
		if(canSwap[i] && canSwap[v[i]])
		{
			if(v[v[i]] == i)
			{
				aux = 2;
				break;
			}
			else aux = 1;
		}
	}
	printf("%d\n", count + aux);

	return 0;
}
