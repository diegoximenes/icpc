#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int n, change25, change50, change75, m;
	bool no = 0;

	scanf("%d", &n);
	change25 = change50 = change75 = 0;
	for(int i=0; i<n; ++i)
	{
		scanf("%d", &m);
		if(no) continue;
		
		if(m == 25) change25++;
		else if(m == 50) 
		{
			if(!change25) no = 1;
			else
			{
				change50++;
				change25--;
			}
		}
		else if(m == 100)
		{
			if(change75 > 0) change75--;
			else if(change25 > 0 && change50 > 0)
			{
				change25--; change50--;
			}
			else if(change25 >= 3)
				change25 -= 3;
			else no = 1;
		}
	}

	if(no) puts("NO");
	else puts("YES");

	return 0;
}

