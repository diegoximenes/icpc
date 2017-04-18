#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> v, d;
    int n, i;
    
    while(1)
    {
	cin >> n;
	
	if(n == 0)
	    break;
	
	v.clear();
	d.clear();
	
	for(i=1; i<=n; i++)
	    v.push_back(i);
	
	for(i=0; i < v.size() - 1; i++)
	{
	    d.push_back(v[i]);
	    i++;
	    v.push_back(v[i]);
	}
	
	cout << "Discarded cards:";
	for(int k=0; k < d.size(); k++)
	{
	    if(k != d.size() - 1)
		cout << " " << d[k] << ",";
	    else
		cout << " " << d[k];
	}
	cout << endl;
	
	cout << "Remaining card: " << v[i] << endl;
    }
    
    return 0;
}