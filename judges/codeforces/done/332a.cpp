#include<cstdio>
#include<cstring>
using namespace std;

#define MAX 2000+10

int main()
{
	int n, lens, delta, count = 0;
	char s[MAX];
	
	gets(s);	
	sscanf(s, "%d", &n);
	gets(s);
	lens = strlen(s);

	for(int i=0; i<lens; i+=n)
		if(i >= 3 && s[i-1] == s[i-2] && s[i-2] == s[i-3])
			++count;
	printf("%d\n", count);

	return 0;
}
