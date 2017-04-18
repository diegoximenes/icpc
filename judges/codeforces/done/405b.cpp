#include<cstdio>
#include<cctype>
#include<cstring>
#include<cmath>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<bitset>
#include<map>
#include<queue>
#include<stack>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair
#define INF 1e9
#define MAX 3005

int main()
{
	int n, cnt = 0;
	char dom[MAX];
	bool mark[MAX];
	
	scanf("%d %s", &n, dom);
	
	bool found = 0;
	for(int i=0; i<n; ++i)
		if(dom[i] != '.')
		{
			found = 1;
			if(dom[i] == 'R') cnt += i;
			break;
		}
	for(int i=n-1; i>=0; --i)
		if(dom[i] != '.')
		{
			if(dom[i] == 'L') cnt += n-i-1;
			break;
		}

	if(!found) cnt += n;
	
	memset(mark, 0, sizeof(mark));
	for(int i=0; i<n; ++i)
	{
		if(dom[i] == 'R' && !mark[i])
		{
			for(int j=i+1; j<n; ++j)
				if(dom[j] != '.')
				{
					if(dom[j] == 'L')
					{
						if((j-i)%2 == 0) ++cnt;
						i = j-1;
						break;
					}
					else mark[j] = 1;
				}
		}
		else if(dom[i] == 'L' && !mark[i])
			for(int j=i+1; j<n; ++j)
				if(dom[j] != '.')
				{
					if(dom[j] == 'R')
					{
						cnt += j - i - 1;
						i = j-1;
						break;
					}
					else mark[j] = 1;
				}
	}

	printf("%d\n", cnt);

	return 0;
}
