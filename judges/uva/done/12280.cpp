#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cctype>
using namespace std;

#define MAX 50

#define isOn(S, j) (S & (1 << j))

inline int w(char c)
{
	int first = 0, w = 0;
	for(int i=7; i>=0; --i)
		if(isOn(c, i))
		{
			first = i;
			break;
		}
	w += 500;

	for(int i=first-1; i>=0; --i)
	{
		if(isOn(c, i))
		 	w+=500;
		 else
		 	w+= 250;
	}
	return w;	
}

int main()
{
	int t, right, left, hright, hleft, iright, ileft, ioutleft, ioutright;
	char line[100], g[MAX][MAX], gout[MAX][MAX];
	
	//printf("a= %d\n", w('A'));
	
	gets(line);
	sscanf(line, "%d", &t);
	for(int tc=1; tc<= t; ++tc)
	{
		right = left = 0;
		for(int i=0; i<7; ++i)
			gets(g[i]);
		gets(line);
		for(int i=0; i<7; ++i)
		{
			for(int j=0; j<18; ++j)
			{
				if(isalpha(g[i][j]))
				{
					int count = w(g[i][j]);
					if(j > 7)
						right += count;
					else
						left += count;
				}
				else if(g[i][j] == '_' )
				{
					if(j > 7)
						hright = i;
					else
						hleft = i;
				}
			}
		}
		
		if(hleft < hright)
		{
			ileft = 0;
			iright = 2;
		}
		else if(hleft > hright)
		{
			ileft = 2;
			iright = 0;
		}
		else
		{
			ileft = 1;
			iright = 1;
		}
		if(left > right)
		{
			ioutleft = 2;
			ioutright = 0;
		}
		else if(left < right)
		{
			ioutleft = 0;
			ioutright = 2;
		}
		else
		{
			ioutleft = 1;
			ioutright = 1;
		}
		
		//printf("rigth= %d, left= %d, hleft= %d, hright= %d, ileft= %d, iright= %d, outleft= %d, outright= %d\n", right, left, hleft, hright, ileft, iright, ioutleft, ioutright);
		
		printf("Case %d:\n", tc);
		if((right == left && hright == hleft) || (right > left && hright > hleft) || (left > right && hleft > hright))
			puts("The figure is correct.");
		else
		{
			for(int i=0; i<7; ++i)
			{
				for(int j=0; j<18; ++j)
				{
					if(j==8 || j==9)
						gout[i][j] = '|';
					else if(j<8)
					{
						if(i < ioutleft || i >= ioutleft+5)
							gout[i][j] = '.';
						else
							gout[i][j] = g[ileft][j];
					}
					else
					{
						if(i < ioutright || i >= ioutright+5)
							gout[i][j] = '.';
						else
							gout[i][j] = g[iright][j];
					}
				}
				if(i >= ioutleft)
					++ileft;
				if(i >= ioutright)
					++iright;
			}
			
			for(int i=0; i<7; ++i, puts(""))
				for(int j=0; j<18; ++j)
					printf("%c", gout[i][j]);
		}
		/*else if(hleft == hright)
		{
			gout[0] = "........||........";
			gout[1] = ".../\...||.../\..."
			gout[6] = "........||........ ";
			for(int i=2; i<6; ++i, iright++, ileft++)
			{
				for(int j=0; j<18; ++j)
				{
					if(j==8 || j==9)
						gout[i][j] = "|";
					else if(j<8)
						gout[i][j] = g[ileft][j];
					else 
						gout[i][j] = g[iright][j];
				}
			}
		}*/
	}
	
	return 0;
}
