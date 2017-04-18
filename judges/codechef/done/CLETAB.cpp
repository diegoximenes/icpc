#include<bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define MMAX 405
#define CMAX 405

int order[MMAX], mostRight[CMAX];

int main()
{
	int t, n, m, c;

	scanf("%d", &t);
	while(t--)
	{
		c = -1;

		scanf("%d %d", &n, &m);
		for(int i=0; i<m; ++i) scanf("%d", &order[i]), c = max(c, order[i]), --order[i];
		
		int clears = 0;
		set<int> customerInTable;

		for(int i=0; i<m; ++i)
		{
			if(customerInTable.find(order[i]) != customerInTable.end()) continue;
			
			++clears;
			if(clears-1 < n)
			{
				customerInTable.insert(order[i]);
				continue;
			}
			
			memset(mostRight, -1, sizeof(mostRight));
			for(int j=i+1; j<m; ++j)
				if(mostRight[order[j]] == -1)
					mostRight[order[j]] = j;
			
			int maxRight = -1, eraseCustomer;
			for(int j=0; j<c; ++j)
			{
				if(customerInTable.find(j) == customerInTable.end()) continue;

				if(mostRight[j] == -1)
				{
					eraseCustomer = j;
					break;
				}
				else if(mostRight[j] > maxRight) maxRight = mostRight[j], eraseCustomer = j;
			}

			customerInTable.erase(eraseCustomer);
			customerInTable.insert(order[i]);
		}

		printf("%d\n", clears);
	}

	return 0;
}
