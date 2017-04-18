#include<iostream>
using namespace std;

typedef long long ll;

int main()
{
	ll a, b, w, x, c, l, r, mid, t1, t, aaux, caux;

	cin >> a >> b >> w >> x >> c;
	aaux = a; caux = c;
	
	if(c <= a)
	{
		cout << 0 << endl;
		return 0;
	}

	l = 0; r = 200000000000010;
	while(l <= r)
	{
		mid = (l + r)/2;
		a = aaux; c = caux;
		
		t1 = (mid*x - b)/w + ((mid*x - b)%w != 0);

		a -= t1; c -= mid;
		if(c <= a) t = mid, r = mid - 1;
		else l = mid + 1;

		//cout << "l= " << (l+r)/2 << ", r= " << (l+r)/2 << ", mid= " << mid << ", a= " << a << ", c= " << c << endl;
	}
	
	cout << t << endl;

	return 0;
}
