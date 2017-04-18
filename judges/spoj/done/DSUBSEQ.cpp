#include<cstdio>
#include<cstring>
using namespace std;

#define MAX 100000+100
#define MOD 1000000007

int main()
{
	int t, alpha[30], len, ch, count[MAX], j;
	char s[MAX];
	
	gets(s);
	sscanf(s, "%d", &t);
	while(t--)
	{
		gets(s);
		memset(alpha, 0, sizeof(alpha));
		count[0] = 1;
		len = strlen(s);
		for(int i=0; i<len; ++i)
		{
			ch = s[i]-'A'; j = i+1;
			count[j] = 2*count[i];
			if(alpha[ch] != 0)
				 count[j] -= count[alpha[ch] - 1];
			alpha[ch] = j;
			
			if(count[j] < 0) count[i+1] += MOD;
			else if(count[j] >= MOD) count[i+1] -= MOD;
		}
		printf("%d\n", count[len]);
	}
	
	return 0;
}