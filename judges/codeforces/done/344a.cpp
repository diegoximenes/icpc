#include<cstdio>
using namespace std;

int main()
{
	int n, count = 1;
	char magnet[3], last;
	
	scanf("%d %s", &n, magnet);
	last = magnet[1];
	while(--n)
	{
		scanf(" %s", magnet);
		if(magnet[0] == last) ++count;
		last = magnet[1];
	}
	printf("%d\n", count);

	return 0;
}
