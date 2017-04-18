#include<cstdio>
#include<vector>
using namespace std;

vector<char> v;

void print()
{
	for(int i=v.size()-1; i>=0; --i)
		printf("%c", v[i]);
}

int main()
{
	char c;
	
	while(scanf("%c", &c) == 1)
	{
		if(c == ' ')
		{
			print();
			putchar(' ');
			v.clear();
		}
		else if(c == '\n')
		{
			print();
			puts("");
			v.clear();
		}
		else
			v.push_back(c);
	}
	print();
	
	return 0;
}