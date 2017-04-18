#include<iostream>
#include<string>
using namespace std;

#define ll long long

int main()
{
	ll nb, ns, nc, pb, ps, pc, countb = 0, countc = 0, counts = 0, auxb, auxc, auxs, r, burger = 0;
	string s;

	cin >> s >> nb >> ns >> nc >> pb >> ps >> pc >> r;
	
	for(int i=0; i<(int)s.size(); ++i)
	{
		if(s[i] == 'B') ++countb;
		else if(s[i] == 'S') ++counts;
		else ++countc;
	}
	if(countb == 0) nb = 0;
	if(counts == 0) ns = 0;
	if(countc == 0) nc = 0;

	while(nb > 0 && ns > 0 && nc > 0)
	{
		auxb = nb; auxs = ns; auxc = nc;
		nb -= countb; ns -= counts; nc -= countc;
		++burger;
	}
	if(nb < 0 || ns < 0 || nc < 0)
	{
		nb = auxb; ns = auxs; nc = auxc;
		--burger;
	}
	
	while((nb != 0 || ns != 0 || nc != 0) && r > 0)
	{
		nb -= countb; ns -= counts; nc -= countc;
		if(nb < 0) r -= -nb*pb, nb = 0;
		if(ns < 0) r -= -ns*ps, ns = 0;
		if(nc < 0) r -= -nc*pc, nc = 0;
		++burger;
	}
	if(r < 0) --burger;

	burger += r/(pb*countb + ps*counts + pc*countc);
	
	cout << burger << endl;

	return 0;
}
