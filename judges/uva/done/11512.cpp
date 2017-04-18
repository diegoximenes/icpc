#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

#define MAXT 1000+10

char t[MAXT];
int n, ra[MAXT], tempra[MAXT], sa[MAXT], tempsa[MAXT], c[MAXT];

int lcp[MAXT], plcp[MAXT], phi[MAXT];

void countingSort(int k)
{
	int i, sum, maxi = max(300, n);
	memset(c, 0, sizeof(c));
	for(i=0; i<n; ++i)
		c[i+k<n ? ra[i+k]: 0]++;
	for(i=sum=0; i<maxi; ++i)
	{
		int t = c[i]; c[i] = sum; sum += t;
	}
	for(i=0; i<n; ++i)
		tempsa[c[sa[i]+k<n ? ra[sa[i]+k] : 0]++] = sa[i];
	for(i=0; i<n; ++i)
		sa[i] = tempsa[i];
}

void constructSA()
{
	int i, k, r;
	for(i=0; i<n; ++i)
	{
		ra[i] = t[i];
		sa[i] = i;
	}
	for(k=1; k<n; k <<= 1)
	{
		countingSort(k);
		countingSort(0);
		tempra[sa[0]] = r = 0;
		for(i=1; i<n; ++i)
			tempra[sa[i]] = (ra[sa[i]] == ra[sa[i-1]] && ra[sa[i]+k] == ra[sa[i-1]+k]) ? r : ++r;
		for(i=0; i<n; ++i)
			ra[i] = tempra[i];
	}
}
			
void computeLCP()
{
	int i, l;
	phi[sa[0]] = -1;
	for(i=1; i<n; ++i)
		phi[sa[i]] = sa[i-1];
	for(i=l=0; i<n; ++i)
	{
		if(phi[i] == -1)
		{
			plcp[i] = 0;
			continue;
		}
		while(t[i + l] == t[phi[i] + l])
			++l;
		plcp[i] = l;
		l = max(l-1, 0);
	}
	for(i=1; i<n; ++i)
		lcp[i] = plcp[sa[i]];
}

int main()
{
	int tc;
	char line[MAXT];
	
	gets(line);
	sscanf(line, "%d", &tc);
	while(tc--)
	{
		gets(t);
		n = strlen(t);
		t[n++] = '$';
		
		constructSA();
		computeLCP();
		
		//for(int i=0; i<n; ++i) printf("%2d\t%s\n", sa[i], t+sa[i]);
		
		int maxlcp = -1, start, count;
		for(int i=0; i<n; ++i)
		{
			if(lcp[i] > maxlcp)
			{
				maxlcp = lcp[i];
				start = i-1;
				count = 2;
			}
			else if(lcp[i] == maxlcp && start+count == i)
				++count;
		}
		if(maxlcp == 0)
			puts("No repetitions found!");
		else
		{
			for(int i=sa[start], j=sa[start+1]; t[i]==t[j]; ++i, ++j)
				putchar(t[i]);
			printf(" %d\n", count);
		}

	}

	return 0;
}
