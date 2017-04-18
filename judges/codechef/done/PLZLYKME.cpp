#include<iostream>
#include<cstdio>
using namespace std;

#define ll long long

int main()
{
	int t;
	unsigned ll l, d, s, c;
	
	cin >> t;
	while(t--)
	{
		cin >> l >> d >> s >> c;
		
		for(unsigned ll i=1; i < d && s < l; ++i, s += c*s);
		puts((s >= l) ? "ALIVE AND KICKING" : "DEAD AND ROTTING");
	}

	return 0;
}
