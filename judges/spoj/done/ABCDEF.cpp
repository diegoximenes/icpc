#include<cstdio>
#include<algorithm>
using namespace std;

#define MAX 105

int left[MAX*MAX*MAX], right[MAX*MAX*MAX];

int main()
{
	int n, v[MAX];

	scanf("%d", &n);
	for(int i=0; i<n; ++i) scanf("%d", &v[i]);
	
	int cntLeft = 0, cntRight = 0; 	
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			for(int k=0; k<n; ++k)
			{
				left[cntLeft++] = v[i] * v[j] + v[k];

				if(v[i] == 0) continue;
				right[cntRight++] = v[i]*(v[j] + v[k]);
			}
	
	sort(left, left + cntLeft);
	sort(right, right + cntRight);
	
	int sol = 0;
	for(int i=0; i<cntLeft; ++i)
	{
		int j;
		for(j=i+1; j<cntLeft; ++j)
			if(left[j] != left[i])
				break;
		--j;
		
		int l = 0, r = cntRight - 1, leftRight = -1, rightRight = -1;
		while(l <= r)
		{
			int mid = (l + r)/2;
			if(right[mid] > left[i]) r = mid - 1;
			else if(right[mid] == left[i]) leftRight = mid, r = mid - 1;
			else l = mid + 1;
		}
		l = 0; r = cntRight - 1;
		while(l <= r)
		{
			int mid = (l + r)/2;
			if(right[mid] > left[i]) r = mid - 1;
			else if(right[mid] == left[i]) rightRight = mid, l = mid + 1;
			else l = mid + 1;
		}
		
		if(leftRight != -1) sol += (j - i + 1) * (rightRight - leftRight + 1);

		i = j;
	}

	printf("%d\n", sol);

	return 0;
}
