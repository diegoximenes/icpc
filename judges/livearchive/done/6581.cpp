#include<cstdio>
#include<cstring>
#include<string>
#include<set>
#include<vector>
using namespace std;

#define pb push_back

int main()
{
	int t;
	char s[110], line[50000];

	scanf("%d", &t);
	gets(line);
	while(t--)
	{
		vector<string> v;
		set<string> mark;
		
		gets(line);
		int p = 0, k;
		while(sscanf(line + p, "%s%n", s, &k) == 1) v.pb(s), p += k;
		
		while(1)
		{
			gets(line);
			if(strcmp(line, "what does the fox say?") == 0) break;
			sscanf(line, "%*s %*s %s", s);
			mark.insert(s);
		}

		bool first = 1;
		for(int i=0; i<(int)v.size(); ++i)
			if(mark.find(v[i]) == mark.end())
			{
				if(!first) printf(" ");
				printf("%s", v[i].c_str());
				first = 0;
			}
		puts("");
	}

	return 0;
}
