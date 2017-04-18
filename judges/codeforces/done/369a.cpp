#include<cstdio>
using namespace std;

int main()
{
	int n, m, k, a;
	
	scanf("%d %d %d", &n, &m, &k);
	while(n--)
	{
		scanf("%d", &a);
		if(a == 1) --m;
		else
		{	 
			if(k > 0 || m < 0) --k;
			else --m;
		}
	}
	int count = 0;
	if(m < 0) count += -m;
	if(k < 0) count += -k;
	printf("%d\n", count);

	return 0;
}
