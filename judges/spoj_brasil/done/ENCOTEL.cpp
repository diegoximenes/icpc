#include<cstdio>
#include<cstring>
using namespace std;

int alg(char c)
{
	if(c == 'A' || c == 'B' || c == 'C') return 2;
	if(c == 'D' || c == 'E' || c == 'F') return 3;
	if(c == 'G' || c == 'H' || c == 'I') return 4;
	if(c == 'J' || c == 'K' || c == 'L') return 5;
	if(c == 'M' || c == 'N' || c == 'O') return 6;
	if(c == 'P' || c == 'Q' || c == 'R' || c == 'S') return 7;
	if(c == 'T' || c == 'U' || c == 'V') return 8;
	else return 9;
}

int main()
{
	char line[35];

	while(scanf(" %s", line) == 1)
	{
		int len = strlen(line);
		for(int i=0; i<len; ++i)
		{
			if(line[i] >= 'A' && line[i] <= 'Z') printf("%d", alg(line[i]));
			else printf("%c", line[i]);
		}
		puts("");
	}

	return 0;
}
