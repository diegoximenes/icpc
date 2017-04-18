#include<cstdio>
#include<cstring>
using namespace std;

#define MAX 65
#define ll long long

ll count(char *s, char state, int height, int size)
{
	ll localcount = 0;

	if(height == size)
	{
		if(state == 'q') return 1;
		return 0;
	}
	if(state == 'p')
	{
		if(s[height] == 'b') localcount += 1*count(s, 'p', height + 1, size) + 1*count(s, 'q', height + 1, size);
		else if(s[height] == 'a') localcount += 1*count(s, 'p', height + 1, size);
	}
	else if(state == 'q')
	{
		if(s[height] == 'b') localcount += 2*count(s, 'q', height + 1, size);
		else if(s[height] == 'a') localcount += 2*count(s, 'q', height + 1, size);
	}
	
	return localcount;
}

int main()
{
	char s[MAX];

	for(int tc=1; scanf(" %s", s) == 1; ++tc)
		printf("Palavra %d\n%lld\n\n", tc, count(s, 'p', 0, strlen(s)));

	return 0;
}
