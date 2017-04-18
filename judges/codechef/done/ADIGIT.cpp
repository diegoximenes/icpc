#include<cstdio>
using namespace std;

#define MAX 100010

int cnt[MAX][10], a[MAX];

int main()
{
	int n, m, x;
	char c;
	
	for(int i=0; i<10; ++i) cnt[0][i] = 0;

	scanf("%d %d \n", &n, &m);
	for(int i=1; i<=n; ++i)
	{
		for(int j=0; j<10; ++j) cnt[i][j] = cnt[i-1][j];
		
		scanf("%c", &c);
		a[i] = c - '0';
		cnt[i][c - '0']++;
	}
	while(m--)
	{
		scanf("%d", &x);

		int sol = 0;
		for(int i=0; i<a[x]; ++i) sol += cnt[x-1][i]*(a[x] - i);
		for(int i=a[x]+1; i<10; ++i) sol += cnt[x-1][i]*(i - a[x]);
		
		printf("%d\n", sol);
	}

	return 0;
}
