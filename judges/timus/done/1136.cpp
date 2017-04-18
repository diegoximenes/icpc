#include<cstdio>
#include<vector>
using namespace std;

#define pb push_back
#define MAX 3005

int n, leftRight[MAX]; 
vector<int> rightLeft;

void print(int l, int r)
{
	if(l > r) return;

	int i;
	for(i=r-1; i>=l && leftRight[i] > leftRight[r]; --i);
	i++;

	print(i, r-1);
	print(l, i-1);
	rightLeft.pb(leftRight[r]);
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; ++i) scanf("%d", &leftRight[i]);

	print(0, n-1);

	printf("%d", rightLeft[0]);
	for(int i=1; i<n; ++i) printf(" %d", rightLeft[i]);
	puts("");

	return 0;
}
