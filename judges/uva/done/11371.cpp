#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
	char s[15];
	long int max, min;
	
	while(gets(s) != NULL)
	{
		sort(s, s+strlen(s));
		max = min = 0;

		long int k = 1;
		for(int i=0; i<(int)strlen(s); ++i)
		{
			max += k*(s[i] - '0');
			k *= 10;
		}

		bool lead = 1;
		for(int i=0; i<(int)strlen(s); ++i)
		{
			if(lead && (s[i] - '0' != 0))
			{
				swap(s[i], s[0]);
				lead = 0;
			}
		}

		k = 1;
		for(int i=(int)strlen(s)-1; i>=0; --i)
		{
			min += k*(s[i] - '0');
			k *= 10;
		}
		
		printf("%ld - %ld = %ld = 9 * %ld\n", max, min, max-min, (max-min)/9);
	}

	return 0;
}