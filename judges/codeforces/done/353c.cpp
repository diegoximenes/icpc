#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAX 100010

int n, a[MAX], cum[MAX];
char s[MAX];

int sum(int i)
{
	if(i == 0) return (s[i] == '1') ? a[i] : 0;
	
	if(s[i] == '0') return sum(i-1);

	return max(sum(i-1) + a[i], cum[i-1]);
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
	{
		scanf("%d", &a[i]);
		if(i == 0) cum[i] = a[i];
		else cum[i] = cum[i-1] + a[i];
	}
	gets(s); gets(s);

	printf("%d\n", sum(strlen(s) - 1));

	return 0;
}