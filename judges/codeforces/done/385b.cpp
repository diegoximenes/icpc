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
#define pb push_back
#define mp make_pair
#define INF 1e9
#define MAX 50005

int main()
{
	char s[MAX];	
	
	scanf(" %s", s);
	ll n = strlen(s), lasti = -1, cnt = 0;

	for(int i=0; i<n; ++i)
		if(i + 3 < n && s[i] == 'b' && s[i+1] == 'e' && s[i+2] == 'a' && s[i+3] == 'r')
		{
			cnt += (n-(i+3))*(i+1);
			if(lasti != -1) cnt -= (n-(i+3))*(lasti+1);
			lasti = i;
		}
	cout << cnt << endl;	

	return 0;
}
