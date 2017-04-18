#include<cstdio>
#include<algorithm>
using namespace std;

#define MAX 110
#define INF (int) 1e9
int give[MAX], receive[MAX];

int main()
{
	int n, m, a, b, c, sol = 0;
	
	scanf("%d %d", &n, &m);
	while(m--)
	{
		scanf("%d %d %d", &a, &b, &c);
		--a; --b;
		give[a] += c;
		receive[b] += c;
	}

	for(int i=0; i<n; ++i)
		if(give[i] > receive[i])
			sol += give[i] - receive[i];

	printf("%d\n", sol);

	return 0;
}
