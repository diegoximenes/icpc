#include<cstdio>
#include<cstring>
#include<string>
#include<cctype>
using namespace std;

#define MAX 50010

string el[150] = {"H","He","Li","Be","B","C","N","O","F","Ne","Na","Mg","Al","Si","P","S","Cl","Ar","K","Ca","Sc","Ti","V","Cr","Mn","Fe","Co","Ni","Cu","Zn","Ga","Ge","As","Se","Br","Kr","Rb","Sr","Y","Zr","Nb","Mo","Tc","Ru","Rh","Pd","Ag","Cd","In","Sn","Sb","Te","I","Xe","Cs","Ba","Hf","Ta","W","Re","Os","Ir","Pt","Au","Hg","Tl","Pb","Bi","Po","At","Rn","Fr","Ra","Rf","Db","Sg","Bh","Hs","Mt","Ds","Rg","Cn","Fl","Lv","La","Ce","Pr","Nd","Pm","Sm","Eu","Gd","Tb","Dy","Ho","Er","Tm","Yb","Lu","Ac","Th","Pa","U","Np","Pu","Am","Cm","Bk","Cf","Es","Fm","Md","No","Lr"};

char s[MAX];
int dp[MAX];

int opt(int i, int len)
{
	if(i == len) return 1;
	if(dp[i] != -1) return dp[i];
	
	bool sol = 0;
	for(int j=0; j<114; ++j)
	{
		bool match = 1;
		if(i + (int)el[j].size() > len) match = 0;
		for(int k=0; k<(int)el[j].size() && match; ++k)
			if(tolower(s[i+k]) != tolower(el[j][k]))
				match = 0;
		if(match)
		{
			sol |= opt(i + el[j].size(), len);
			if(sol) break;
		}
	}
	return dp[i] = sol;
}

int main()
{
	int tc;

	scanf("%d", &tc);
	while(tc--)
	{
		memset(dp, -1, sizeof(dp));
		scanf(" %s", s);
		if(opt(0, strlen(s))) puts("YES");
		else puts("NO");
	}

	return 0;
}
