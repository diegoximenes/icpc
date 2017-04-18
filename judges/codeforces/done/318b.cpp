#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

#define MAX 1000000+10

int main()
{
	int n, indh[MAX], indm[MAX], countm = 0, counth = 0;
	char s[MAX];

	gets(s);
	n = strlen(s);
	for(int i=0; i<=n-5; ++i)
	{
		if(!strncmp(s+i, "heavy", 5)) indh[counth++] = i;
		if(!strncmp(s+i, "metal", 5)) indm[countm++] = i;
	}

	long long count = 0;
	for(int i=0, j=0; i<counth && j<countm; )
	{
		if(indh[i] < indm[j])
		{
			count += countm - j;
			++i;
		}
		else
			++j;
	}
	cout << count << endl;

	return 0;
}
