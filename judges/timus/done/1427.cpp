#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAX 100000 + 100

bool isvalid(char c)
{
	if(isalpha(c) || c == ' ')
		return 1;
	return 0;
}

int main()
{
	int n, m;
	char s[MAX];
	
	gets(s);
	sscanf(s, "%d %d", &n, &m);
	gets(s);

	int len = strlen(s), packs = 0;
	for(int i=0; i<len; )
	{
		++packs;
		
		int j;
		for(j=i; j<min(len, i+m); ++j)
			if(!isvalid(s[j]))
				break;
			
		if(j < i+n)
			i += n;
		else
			i += j-i;
	}

	printf("%d\n", packs);
	
	return 0;
}