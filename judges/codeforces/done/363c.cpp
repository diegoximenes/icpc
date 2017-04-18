#include<cstdio>
#include<cstring>
using namespace std;

#define MAX 200010

int main()
{
	char s[MAX], actual;
	int countLast, countActual;
	bool mark[MAX];
	
	scanf(" %s", s);
	memset(mark, 0, sizeof(mark));
	countLast = countActual = 0; 
	actual = 0;
	int len = strlen(s);
	for(int i=0; i<len; ++i)
	{
		if(s[i] == actual) ++countActual;
		else
		{
			countLast = countActual;
			countActual = 1;
		}
		actual = s[i];

		if(countActual > 2) mark[i] = 1, --countActual;
		if(countActual == 2 && countLast >= 2) mark[i] = 1, --countActual;
	}

	for(int i=0; i<len; ++i)
		if(!mark[i])
			putchar(s[i]);
	puts("");

	return 0;
}