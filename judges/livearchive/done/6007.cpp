#include<cstdio>
#include<cctype>
#include<cstring>
#include<string>
#include<vector>
using namespace std;

#define pb push_back

int main()
{
	int tc, n;
	char word[15];

	scanf("%d", &tc);
	while(tc--)
	{
		bool found = 0;
		vector<string> before, after;
		string english;

		scanf("%d", &n);
		for(int i=0; i<n; ++i)
		{
			scanf(" %s", word);
			if(word[0] != '#') 
			{
				english = word;
				found = 1;
			}
			else if(found) after.pb(word);
			else before.pb(word);
		}
		
		if(after.size() > 0) printf("%s", after[0].c_str());
		for(int i=1; i<(int)after.size(); ++i)
			printf(" %s", after[i].c_str());
		if(found) 
		{
			if(after.size() > 0) putchar(' ');
			printf("%s", english.c_str());

			if(before.size() > 0) printf(" %s", before[0].c_str());
		}
		else if(before.size() > 0) printf("%s", before[0].c_str());
		for(int i=1; i<(int)before.size(); ++i)
			printf(" %s", before[i].c_str());
		puts("");
	}
	return 0;
}
