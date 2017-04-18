#include<cstdio>
#include<cstring>
using namespace std;

typedef long long ll;
#define MAX 10005
#define MOD (int)(1e9 + 7)

char s[MAX];

int main()
{
	int t;

	scanf("%d", &t);
	while(t--)
	{
		scanf(" %s ", s);
		int n = strlen(s);
		
		ll sol = 1;
		for(int i=0; i<n; ++i)
			if(s[i] == '?')
			{
				int l = i-1;
				while(i < n && s[i] == '?') ++i;

				if(i < n && l >= 0 && s[l] != s[i]) sol = (sol * (ll)(i - l))%MOD;
			}
		
		printf("%lld\n", sol);
	}

	return 0;
}
