#include<cstdio>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;

int main()
{
	int len, count[30], maxcount = 0;
	char line[100];

	memset(count, 0, sizeof(count));
	for(int i=0; i<4; ++i)
	{
		gets(line);
		len = strlen(line);
		for(int i=0; i<len; ++i)
			if(isalpha(line[i]))
			{
				++count[line[i] - 'A'];
				maxcount = max(count[line[i] - 'A'], maxcount);
			}
	}
	for(int i=maxcount; i>=1; --i)
	{
		char last = 'Z';
		for(char c='A'; c<='Z'; ++c)
			if(count[c - 'A'] == i)
				last = c;
		for(char c='A'; c<=last; ++c)
		{
			if(count[c - 'A'] == i) 
			{
				putchar('*');
				--count[c-'A'];
			}
			else putchar(' ');
			if(c != last) putchar(' ');
		}
		puts("");
	}
	putchar('A');
	for(char c='B'; c<='Z'; ++c)
		printf(" %c", c);
	puts("");			

	return 0;
}
