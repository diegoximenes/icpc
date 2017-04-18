#include<cstdio>
using namespace std;

typedef long long ll;
#define MAX 100005

char s[MAX];

int main()
{
	int t, n;

	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %s ", &n, s);
		
		ll sol = 0, cntOne = 0;
		for(int i=0; i<n; ++i)
			if(s[i] == '1')
				cntOne++, sol += cntOne;

		printf("%lld\n", sol);
	}

	return 0;
}
