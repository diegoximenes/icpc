#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;

#define MAX 1000010
#define ll long long

char s[MAX];

int main()
{
	ll left = 0, right = 0;
	int mid;	
	bool isRight = 1;
	
	scanf("%s", s);
	int len = strlen(s);
	for(int i=0; i<len; ++i) if(s[i] == '^') mid = i;
	for(int i=len-1; i>=0; --i)
	{
		if(s[i] == '^') isRight = 0;
		else if(s[i] == '=') continue;
		else
		{
			if(isRight) right += (i - mid)*(s[i] - '0');
			else left += (mid - i)*(s[i] - '0');
		}
	}
	
	if(left == right) puts("balance");
	else if(left > right) puts("left");
	else puts("right");

	return 0;
}
