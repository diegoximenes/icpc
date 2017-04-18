#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int t;
	char s[100010];

	scanf("%d", &t);
	while(t--)
	{
		scanf(" %s", s);
		int n = strlen(s);
		bool good = 0;
		for(int i=0; !good && i<=n-3; ++i)
			if(s[i] != s[i+1] && s[i+1] != s[i+2])
				good = 1;
		puts( good ? "Good" : "Bad");
	}

	return 0;
}
