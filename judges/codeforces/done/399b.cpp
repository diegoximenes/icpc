#include<cstdio>
#include<cctype>
#include<cstring>
#include<cmath>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<bitset>
#include<map>
#include<queue>
#include<stack>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define pb push_back
#define mp make_pair
#define INF 1e9
#define MAX 55

int main()
{
	int n, last = -1;
	char s[MAX];
	ll cnt = 0;
	
	scanf("%d %s", &n, s);
	
	for(int i=n-1; i>=0; --i)
		if(s[i] == 'B')
		{ 
			last = i;
			break;
		}
	for(int i=last; i>=0; --i)
		if(s[i] == 'B')
			cnt += pow(2, i);

	cout << cnt << endl;

	return 0;
}
