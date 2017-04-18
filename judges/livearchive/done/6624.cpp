#include<cstdio>
#include<cstring>
#include<cctype>
using namespace std;

#define MAX 1500

int n, m, card[MAX], last;
double dp[MAX];
bool mark[MAX];

double opt(int i)
{
	if(i > last) return 0;
	if(card[i] != 0) return 1;
	double &state = dp[i];
	if(mark[i]) return state;

	double sol = 0;
	for(int j=2; j<=11; ++j) sol += 1.0/13.0 * opt(i + j);
	sol += 3.0*1.0/13.0 * opt(i + 10);
	
	mark[i] = 1;
	return state = sol;
}

int main()
{
	char in[10];

	while(scanf("%d %d", &n, &m) == 2)
	{
		memset(card, 0, sizeof(card));
		int j = m - 1;
		for(int i=0; i<n; ++i)
		{
			scanf(" %s ", in);
			if(isdigit(in[0]))
			{
				if(strlen(in) == 2) card[j] = 10;
				else card[j] = in[0] - '0';
			}
			else if(in[0] == 'A') card[j] = 11;
			else card[j] = 10;
			
			last = j;
			j += card[j];
		}
		
		memset(mark, 0, sizeof(mark));
		double sol = 0;
		for(int i=0; i<10; ++i) sol += opt(i)*1.0/10.0;
		printf("%.8lf\n", sol);
	}
	return 0;
}
