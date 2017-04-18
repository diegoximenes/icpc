#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

#define MAX 100005

int main()
{
	int n, m, v1 = 1, v2;
	long long int dist = 0;

	scanf("%d %d", &n, &m);
	for(int i=0; i<m; ++i)
	{
		scanf("%d", &v2);
		if(v2 >= v1) dist += v2 - v1;
		else dist += n - v1 + 1 + v2 - 1;
		v1 = v2;
	}
	cout << dist << endl;

	return 0;
}
