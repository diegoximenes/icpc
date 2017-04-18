#include<iostream>
using namespace std;

#define ll long long 

int main()
{
	ll x, y, m, a, b, count = 0;
	
	cin >> x >> y >> m;

	a = min(x, y); b = max(x, y);
	
	if(a >= m || b >= m)
	{
		cout << "0" << endl;
		return 0;
	}
	if(a <= 0 && b <= 0)
	{
		cout << "-1" << endl;
		return 0;
	}
	
	if(a < 0)
	{
		count = -a/b + 1;
		a = count*b + a;
	}
	//cout << "a= " << a << "b = " << b << endl;
	while(a < m &&  b < m)
	{
		++count;
		if(a < b)
			a = a + b;
		else
			b = a + b;
	}
	cout << count << endl;

	return 0;
}
