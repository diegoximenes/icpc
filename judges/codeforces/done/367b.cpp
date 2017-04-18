#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

#define pb push_back
#define mp make_pair
#define MAX 200010

int n, m, p, a, b[MAX];
vector< pair<int, int> > pos[MAX];
map<int, int> count1;

int main()
{
	scanf("%d %d %d", &n, &m, &p);
	for(int i=0; i<n; ++i)
	{
		scanf("%d", &a);
		pos[i%p].pb(mp(a, i));
	}
	for(int i=0; i<m; ++i)
	{
		scanf("%d", &b[i]);
		if(count1.find(b[i]) == count1.end()) count1[b[i]] = 1;
		else count1[b[i]]++;
	}

	vector<int> out;
	for(int i=0; i<p; ++i)
		if((int)pos[i].size() >= m)
		{
			int match = 0;
			map<int, int> count2;
			
			for(int j=0; j<(int)pos[i].size(); ++j)
			{
				bool matchRight = count2[pos[i][j].first] == count1[pos[i][j].first], matchLeft = 0;

				if(j >= m)
				{
					matchLeft = count2[pos[i][j-m].first] == count1[pos[i][j-m].first];
					count2[pos[i][j-m].first]--;
				}
				count2[pos[i][j].first]++;
				
				if(j >= m)
				{
					if(matchLeft) match -= count1[pos[i][j-m].first];
					if(matchRight && pos[i][j].first != pos[i][j-m].first) match -= count1[pos[i][j].first];
				}
				else if(matchRight) match -= count1[pos[i][j].first];				
	
				if(count2[pos[i][j].first] == count1[pos[i][j].first]) match += count2[pos[i][j].first];
				if(j >= m && pos[i][j].first != pos[i][j-m].first && count2[pos[i][j-m].first] == count1[pos[i][j-m].first]) match += count1[pos[i][j-m].first];	
				
				if(match == m) out.pb(pos[i][j-m+1].second + 1);
				//printf("j= %d, match= %d, count2[1]= %d, count2[2]= %d, count2[3]= %d\n", j, match, count2[1], count2[2], count2[3]);
			}
		}
	
	printf("%d\n", out.size());
	sort(out.begin(), out.end());
	if((int)out.size() > 0)
	{
		printf("%d", out[0]);
		for(int i=1; i<(int)out.size(); ++i) printf(" %d", out[i]);
		puts("");
	}

	return 0;
}
