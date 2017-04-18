#include<cstdio>
using namespace std;

#define MAX 33000

int main()
{
	int n, c, v[MAX];

	scanf("%d %d", &n, &c);
	for(int i=0; i<n; ++i)
		scanf("%d", &v[i]);

	for(int i=c%n, j=0; j<10; ++j, ++i)
		printf("%d", v[i%n]);
	puts("");

	return 0;
}
