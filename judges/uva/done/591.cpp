#include<iostream>
using namespace std;

int main()
{
	int n;
	
	for(int k = 1; ; k++)
	{	
		cin >> n;
		
		if(n == 0) break;
		
		//if(k != 1) cout << endl;
		
		int v[n], b = 0, t, m = 0;

		for(int i=0; i<n; i++)
		{
			cin >> v[i];
			
			b += v[i];	
		}

		t = b/n;

		for(int i=0; i<n; i++)
			if(v[i] > t)
				m += v[i] - t;
		
		cout << "Set #" << k << endl << "The minimum number of moves is " << m << "." << endl << endl;
	}
	
	return 0;
}