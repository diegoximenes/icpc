#include<cstdio>
#include<cstring>
using namespace std;

#define MAX 105

int main()
{
	int t, c, v, candidate[MAX], voter[MAX][MAX];
	
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &c, &v);
		for(int i=0; i<v; ++i)
			for(int j=0; j<c; ++j)
			{
				scanf("%d", &voter[i][j]);
				--voter[i][j];
			}

		int countVotes = 0;
		bool solved = 0;
		memset(candidate, 0, sizeof(candidate));
		for(int i=0; i<v; ++i)
			for(int j=0; j<c; ++j)
				if(voter[i][j] < c)
				{
					++candidate[voter[i][j]];
					++countVotes;
					break;
				}
		int max1 = -1, max2 = -1, cand1, cand2;
		for(int i=0; i<c; ++i)
		{
			if(candidate[i] > (double)countVotes/2.0)
			{
				solved = 1;
				printf("%d %d\n", i+1, 1);
				break;
			}
			if(candidate[i] > max1)
			{
				max2 = max1;
				cand2 = cand1;
				max1 = candidate[i];
				cand1 = i;
			}
			else if(candidate[i] > max2)
			{
				max2 = candidate[i];
				cand2 = i;
			}
		}
		
		if(!solved)
		{
			int count1 = 0, count2 = 0;
			for(int i=0; i<v; ++i)
				for(int j=0; j<c; ++j)
				{
					if(voter[i][j] == cand1) 
					{
						++count1;
						break;
					}
					if(voter[i][j] == cand2) 
					{
						++count2;
						break;
					}
				}
			if(count1 > count2)
				printf("%d %d\n", cand1+1, 2);
			else
				printf("%d %d\n", cand2+1, 2);
		}
	}
	
	return 0;
}
