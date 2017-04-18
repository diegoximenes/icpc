#include<cstdio>
#include<cstring>
#include<map>
using namespace std;

#define MAX 1000010

int t, r;
char x, y, s[MAX];

int main()
{
	scanf("%d", &t);
	while(t--)
	{
		map<char, char> rule;
		scanf("%d", &r);
		while(r--)
		{
			scanf(" %c %c ", &x, &y);
			rule[x] = y;
		}

		scanf(" %s ", s);
		int n = strlen(s);
		for(int i=0; i<n; ++i)
			if(rule.find(s[i]) != rule.end())
				s[i] = rule[s[i]];
	
		int left = n-1;	
		for(int i=0; i<n; ++i)
			if(s[i] != '0')
			{
				left = i;
				break;
			}
		
		int right = n-1;
		for(int i=n-1; i>=0; --i)
		{
			if(s[i] != '0' && s[i] != '.')
			{
				right = i;
				break;
			}
			if(s[i] == '.')
			{
				right = i-1;
				break;
			}
		}
		
		bool foundPoint = 0;
		for(int i=0; i<n; ++i)
			if(s[i] == '.')
			{
				foundPoint = 1;
				break;
			}
		if(!foundPoint) right = n-1;

		if(right < left || (left == right && s[left] == '.')) puts("0");
		else
		{
			for(int i=left; i<=right; ++i) putchar(s[i]);
			puts("");
		}
	}

	return 0;
}
