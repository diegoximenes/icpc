#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

int main()
{
	char s[1010], out[1010], c;
	int count['z'-'a' + 5], count2['z' - 'a' + 5], countSol['z' - 'a' + 5];
	int n, len, i;
	double sheet;

	gets(s);
	scanf("%d", &n);
	len = strlen(s);
	memset(count, 0, sizeof(count));
	memset(count2, 0, sizeof(count2));
	memset(countSol, 0, sizeof(countSol));

	for(i=0; i<len; ++i)
	{
		++count2[s[i] - 'a'];
		++count[s[i] - 'a'];
	}

	for(i=0, c='a'; i<n && c<='z'; ++c)
		if(count[c - 'a'] > 0)
		{
			out[i++] = c;
			--count[c-'a'];
			++countSol[c - 'a'];
		}

	while(i < n)
	{
		int maxcount = 0;
		char maxl = 'a';
		for(c='a'; c<='z'; ++c)	
			if((double)count[c - 'a']/(double)countSol[c-'a'] > (double)maxcount)
			{
				maxcount = (double)count[c - 'a']/(double)countSol[c-'a'];
				maxl = c;
			}
		out[i++] = maxl;
		--count[maxl - 'a'];
		++countSol[maxl - 'a'];
	}

	sheet = 0;
	for(c='a'; c<='z'; ++c)
	{
		if(countSol[c-'a'] == 0 && count2[c-'a'] > 0)
		{
			puts("-1");
			return 0;
		}
		sheet = max(sheet, ceil((double)count2[c-'a']/(double)countSol[c-'a']));
	}

	printf("%d\n", (int)ceil(sheet));
	for(i=0; i<n; ++i)
		putchar(out[i]);
	puts("");

	return 0;
}

