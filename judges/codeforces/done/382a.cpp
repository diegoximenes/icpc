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

#define ll long long
#define pb push_back
#define mp make_pair
#define INF 1e9

int main()
{
	string s, t;
	deque<char> out;
	
	cin  >> s >> t;
	int lens = s.size(), lent = t.size(), cntl = 0, cntr = 0;
	bool isLeft = 1;
	for(int i=0; i<lens; ++i)
	{
		if(s[i] == '|') isLeft = 0;
		else if(isLeft) cntl++;
		else cntr++;
		out.pb(s[i]);
	}
	
	for(int i=0; i<lent; ++i)
	{
		if(cntl > cntr) out.pb(t[i]), ++cntr;
		else out.push_front(t[i]), ++cntl;
	}

	if(cntl != cntr) puts("Impossible");
	else
	{
		for(int i=0; i<(int)out.size(); ++i)
			putchar(out[i]);
		puts("");
	}

	return 0;
}
