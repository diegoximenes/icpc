/*
LIS (Longest Increasing Subsequence) - O(n*logn)
*/

#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int n;

void lis(const vector<int> &v, vector<int> & asw)
{
	vector<int> pd(v.size(), 0), pd_index(v.size()), pred(v.size());
	int maxi = 0, x, j, ind;
	for(int i=0; i<n; ++i)
	{
		x = v[i];
		j = lower_bound(pd.begin(), pd.begin() + maxi, x) - pd.begin();
		//j = upper_bound(pd.begin(), pd.begin() + maxi, x) - pd.begin(); // para LDS
		pd[j] = x;
		pd_index[j] = i;
		if(j == maxi)
		{
			++maxi;
			ind = i;
		}
		pred[i] = j ? pd_index[j-1] : -1;
	}
	//return maxi; caso a sequencia nao precise ser refeita
	
	int pos = maxi - 1, k = v[ind];
	asw.resize(maxi);
	while(pos >= 0)
	{
		asw[pos--] = k;
		ind = pred[ind];
		k = v[ind];
	}
}

int main()
{
	int e;
	vector<int> v, asw;
	while(scanf("%d", &e) != EOF)
		v.push_back(e);
	n = v.size();
	lis(v, asw);
	printf("%d\n-\n", (int)asw.size());
	for(int i=0; i<(int)asw.size(); ++i)
		printf("%d\n", asw[i]);
	return 0;
}