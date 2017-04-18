#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

#define MAX 110

int main()
{
	int T;
	char s[MAX], t[MAX];
	bool match[MAX];

	scanf("%d", &T);
	for(int tc=1; tc<=T; ++tc)
	{
		scanf(" %s %s", s, t);
		
		memset(match, 0, sizeof(match));
		int cnt = 0, n = strlen(s);

		for(int i=0; i<n; ++i)
		{
			if(s[i] == t[i]) match[i] = 1;
			if(match[i]) continue;
			if(s[i] != t[i] && s[i] != '?')
			{
				bool swaped = 0;
				for(int j=i+1; j<n; ++j)
					if(!match[j] && s[i] != s[j] && t[i] != t[j] && s[j] != '?')
					{
						match[i] = match[j] = 1; 
						cnt++;
						swaped = 1;
						break;
					}
				if(!swaped && s[i] == '0') ++cnt, match[i] = 1;
			}
		}

		bool can = 1;
		for(int i=0; can && i<n; ++i)
			if(!match[i] && s[i] == '1')
			{
				bool swaped = 0;
				for(int j=0; j<n; ++j)
					if(s[j] == '?' && t[j] == '1' && !match[j])
					{
						match[i] = match[j] = 1; 
						cnt+=2;
						swaped = 1;
						break;
					}
					
				if(!swaped) can = 0;
			}
		
		for(int i=0; i<n; ++i)
			if(!match[i] && s[i] == '?')
				++cnt;

		printf("Case %d: %d\n", tc, can ? cnt : -1);
	}

	return 0;
}
