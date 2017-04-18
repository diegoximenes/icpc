#include<cstdio>
#include<algorithm>
#include<climits>
#include<cstdlib>
using namespace std;

bool valid(int *row)
{
	for(int i=0; i<8; ++i)
		for(int j=i+1; j<8; ++j)
		{
			if(row[i] == row[j])
				return 0;
			
			if(abs(i-j) == abs(row[i]-row[j]))
				return 0;
		}
	
	return 1;
}

int main()
{	
	int rowaux[8], minmove;
	bool flag = 0;
	
	for(int k=1; ; ++k)
	{
		for(int i=0; i<8; ++i)
			if(scanf("%d", &rowaux[i]) == EOF)
			{
				flag = 1;
				break;
			}
			
		if(flag)
			break;
		
		int row[] = {1, 2, 3, 4, 5, 6, 7, 8};
		minmove = INT_MAX;
		while(1)
		{			
			if(!next_permutation(row, row + 8))
				break;
			
			int moves = 0;
			if(valid(row))
			{
				for(int i=0; i<8; ++i)
					if(row[i] != rowaux[i])
						++moves;
				
				minmove = min(moves, minmove);
			}
		}
		
		printf("Case %d: %d\n", k, minmove);
	}
	return 0;
}