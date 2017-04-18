#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int n;
	char p[100010];

	scanf("%d", &n);
	for(int i=0; i<n; ++i)
	{
		scanf(" %s", p);
		int len = strlen(p), count = 0;
		for(int i=0; i<len-2; ++i)
		{
			if(p[i+1] == '0' && ((p[i] == '|' && p[i+2] == '|') || (p[i] == '/' && p[i+2] == '/') || (p[i] == '\\' && p[i+2] == '\\') || (p[i] == '\\' && p[i+2] == '/')))
			{
				++count;
				p[i+2] = ' ';
			}
		}
		if(count == 0) puts("That Bad Party xD");
		else printf("%d\n", count);
	}

	return 0;
}
