#include<cstdio>
#include<cstring>
#include<deque>
using namespace std;

#define MAX 2005

char s[MAX];

int main()
{
	for(int tc=1; scanf(" %s ", s) && s[0] != '-'; ++tc)
	{
		int n = strlen(s);
		deque<char> st;
		for(int i=0; i<n; ++i)
		{
			if(s[i] == '{') st.push_back('{');
			else if(!st.empty() && st.back() == '{') st.pop_back();
			else st.push_back('}');
		}

		int sol = 0;
		bool solved = 0;
		for(int i=0; i<(int)st.size(); ++i)
			if(st[i] == '{')
			{
				sol += max(0, i/2 + i%2);
				int aux = (int)st.size() - i;
				sol += max(0, aux/2 + aux%2);
				
				solved = 1;
				break;
			}
		if(!solved) sol = (int)st.size()/2;
		
		printf("%d. %d\n", tc, sol);
	}

	return 0;
}
