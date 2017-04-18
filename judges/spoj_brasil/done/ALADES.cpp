#include<cstdio>
using namespace std;

int main()
{
	int h1, m1, h2, m2, minEndDay = 60*24;

	while(scanf("%d %d %d %d", &h1, &m1, &h2, &m2) && (h1 != 0 || m1 != 0 || h2 != 0 || m2 != 0))
	{
		if(h2 < h1 || (h1 == h2 && m2 < m1))
			printf("%d\n", minEndDay - h1*60 - m1 + h2*60 + m2);
		else
			printf("%d\n", 60*h2 + m2 - 60*h1 - m1);
	}
		
	return 0;
}
