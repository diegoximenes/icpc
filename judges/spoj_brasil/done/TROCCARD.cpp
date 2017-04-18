#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

#define MAX 100010
#define pb push_back

int main()
{
	int a, b;
	bool acard[MAX], bcard[MAX];
	vector<int> avec, bvec;

	while(scanf("%d %d", &a, &b) && a)
	{
		int c;
		memset(acard, 0, sizeof(acard));
		memset(bcard, 0, sizeof(bcard));
		avec.clear(); bvec.clear();

		for(int i=0; i<a; ++i)
		{
			scanf("%d", &c);
			if(avec.size() > 0 && avec.back() == c) continue;
			acard[c] = 1;
			avec.pb(c);
		}
		for(int i=0; i<b; ++i)
		{
			scanf("%d", &c);
			if(bvec.size() > 0 && bvec.back() == c) continue;
			bcard[c] = 1;
			bvec.pb(c);
		}

		int countA = 0, countB = 0;
		for(int i=0; i<(int)avec.size(); ++i)
			if(bcard[avec[i]] == 0)
				++countA;
		for(int i=0; i<(int)bvec.size(); ++i)
			if(acard[bvec[i]] == 0)
				++countB;
		printf("%d\n", min(countA, countB));
	}
		
	return 0;
}
