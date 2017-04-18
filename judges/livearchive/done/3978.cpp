#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
using namespace std;

#define MAX 1010
#define pb push_back

int n, tc, len, count[MAX][MAX][30], dp[MAX];
char text[MAX], word[110];
vector<string> dic;
bool solved;

int opt(int i)
{
	int letterCount[30];
	
	if(solved) return 2;	
	if(i == len) return 1;
	if(dp[i] != -1) return dp[i];
	
	int sol = 0;
	for(int j=0; j<(int)dic.size(); ++j)
	{
		if(dic[j][0] != text[i] || dic[j][dic[j].size() - 1] != text[i + dic[j].size() - 1]) continue;
		bool can = 1;
		memset(letterCount, 0, sizeof(letterCount));	
		for(int k=0; k<(int)dic[j].size(); ++k) ++letterCount[dic[j][k] - 'a'];
		for(char c='a'; can && c<='z'; ++c)
			if(count[i][i + dic[j].size() - 1][c - 'a'] != letterCount[c - 'a'])
				can = 0;
		if(can) 
		{
			sol += opt(i + dic[j].size());
			if(sol > 1) 
			{
				solved = 1;
				return 2;
			}
		}
	}

	return dp[i] = sol;
}

void print(int i)
{
	int letterCount[30];
	
	if(i == len) return;
	
	for(int j=0; j<(int)dic.size(); ++j)
	{
		if(dic[j][0] != text[i] || dic[j][dic[j].size() - 1] != text[i + dic[j].size() - 1]) continue;
		bool can = 1;
		memset(letterCount, 0, sizeof(letterCount));	
		for(int k=0; k<(int)dic[j].size(); ++k) ++letterCount[dic[j][k] - 'a'];
		for(char c='a'; can && c<='z'; ++c)
			if(count[i][i + dic[j].size() - 1][c - 'a'] != letterCount[c - 'a'])
				can = 0;
		if(can && opt(i) == opt(i + dic[j].size())) 
		{
			if(i != 0) putchar(' ');
			printf("%s", dic[j].c_str());
			print(i + dic[j].size());
		}
	}
}

int main()
{
	scanf("%d", &tc);
	while(tc--)
	{
		scanf(" %s", text);
		len = strlen(text);
		
		dic.clear();
		scanf("%d", &n);
		int maxlen = 0;
		while(n--)
		{
			scanf(" %s", word);
			dic.pb(word);
			maxlen = (maxlen > (int)strlen(word)) ? maxlen : strlen(word);
		}
		
		memset(count, 0, sizeof(count));
		for(int i=0; i<len; ++i)
		{
			++count[i][i][text[i] - 'a'];
			int upper = (i + maxlen < len) ? i + maxlen : len;
			for(int j=i+1; j<upper; ++j)
			{
				for(char c='a'; c<='z'; ++c) count[i][j][c - 'a'] = count[i][j-1][c - 'a'];
				++count[i][j][text[j] - 'a'];
			}
		}

		solved = 0;		
		memset(dp, -1, sizeof(dp));
		if(opt(0) == 0) puts("impossible");
		else if(opt(0) == 1) 
		{ 
			print(0); 
			puts(""); 
		}
		else puts("ambiguous");
	}

	return 0;
}
