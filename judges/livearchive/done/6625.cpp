#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

#define pb push_back
#define MAX 8
#define MAXCOLSTATE (777777 + 100)

int dp[MAX][MAXCOLSTATE], numCols;
int col[MAX], rowSize[MAX], cntRows[MAX];
vector< vector<int> > colSol[MAX][MAX];

void solveCol(int i, int n, int k)
{
	if(i == n)
	{
		vector<int> v;
		for(int j=0; j<n; ++j) v.pb(col[j]);
		colSol[n][k].pb(v);
	}
	
	for(int j=1; j<=k; ++j)
		if((i-1 >= 0 && col[i-1] < j) || (i-1 < 0))
			col[i] = j, solveCol(i+1, n, k);
}

inline int getColState(vector<int> &lastCol)
{
	int state = 0, n = lastCol.size();

	int lower = 0;
	if(n == 7) lower = 1;
	
	for(int i=lastCol.size()-1, k=1; i>=lower; --i, k*=10) state += k*lastCol[i];
	return state;
}
	
int main()
{
	for(int i=1; i<=7; ++i)
		for(int j=i; j<=7; ++j)
			solveCol(0, i, j);
	
	int n, k;
	while(scanf("%d", &n) == 1)
	{
		numCols = -1;
		for(int i=0; i<n; ++i)
		{
			scanf("%d", &rowSize[i]);
			numCols = max(numCols, rowSize[i]);
		}
		scanf("%d", &k);
		
		for(int j=0; j<numCols; ++j)
		{
			cntRows[j] = 0;
			for(int i=0; i<n; ++i) 
			{
				if(rowSize[i] > j) cntRows[j]++;
				else break;
			}
		}

		vector<int> firstCol;
		for(int i=0; i<cntRows[0]; ++i) firstCol.pb(0);
		
		vector< vector<int> > cols;
		for(int j=numCols-1; j>=0; --j)
		{
			if(j - 1 < 0) cols.pb(firstCol);
			else cols = colSol[cntRows[j-1]][k];

			for(int l=0; l<(int)cols.size(); ++l)
			{	
				vector<int> lastCol = cols[l];

				int numRows = cntRows[j], sol = 0;
				for(int i=0; i<(int)colSol[numRows][k].size(); ++i)
				{
					bool can = 1;
					for(int l=0; can && l<(int)colSol[numRows][k][i].size(); ++l)
						if(lastCol[l] > colSol[numRows][k][i][l])
							can = 0;

					if(can)
					{
						if(j+1 == numCols) sol++; 
						else sol += dp[j+1][getColState(colSol[numRows][k][i])];
					}
				}

				dp[j][getColState(cols[l])] = sol;
			}
		}

		printf("%d\n", dp[0][getColState(firstCol)]);
	}

	return 0;
}
