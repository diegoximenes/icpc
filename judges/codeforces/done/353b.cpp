#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 210

int main()
{
	int cubes[MAX], count[MAX], n, upper, mark[MAX], mark2[MAX], count1 = 0, count2 = 0;

	scanf("%d", &n); upper = 2*n;
	memset(count, 0, sizeof(count));
	for(int i=0; i<upper; ++i)
	{
		scanf("%d", &cubes[i]);
		count[cubes[i]]++;
	}
	
	memset(mark2, 0, sizeof(mark2));
	memset(mark, 0, sizeof(mark));
	for(int i=0; i<upper; ++i)
	{
		if(count[cubes[i]] > 1) 
		{
			if(!mark2[cubes[i]])
			{
				mark2[cubes[i]] = 1;
				mark[i] = 1;
				++count1;
			}
			else if(mark2[cubes[i]] == 1)
			{
				mark2[cubes[i]] = 2;
				mark[i] = 2;
				++count2;
			}
		}
	}
	
	for(int i=0; i<upper; ++i)
		if(count[cubes[i]] == 1)
		{
			if(count1 < count2) mark[i] = 1, ++count1;
			else mark[i] = 2, ++count2;
		}

	int auxcount1 = count1, auxcount2 = count2;
	for(int i=0; i<upper; ++i)
		if(count[cubes[i]] > 2 && mark[i] == 0)
		{
			if(auxcount1 < auxcount2) mark[i] = 1, ++auxcount1;
			else mark[i] = 2, ++auxcount2;

		}
	
	printf("%d\n%d", count1*count2, mark[0]);
	for(int i=1; i<upper; ++i) printf(" %d", mark[i]);
	puts("");
	
	return 0;
}
