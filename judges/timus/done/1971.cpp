#include<cstdio>
#include<map>
#include<string>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;

#define ll long long
#define EPS 1e-9

int main()
{
	map<string, int> dic;
	char op[20];
	int n, m, w, h, cycle;
	double logcumcycle = 0, log60 = log(60), log10 = log(10);

	scanf("%d", &n);
	for(int i=0; i<n; ++i)
	{
		scanf(" %s", op);
		cin >> cycle;
		logcumcycle += log(cycle);
		dic[op] = cycle;
	}	
	
	cin >> w >> h >> cycle >> m;
	double logcycle = log(cycle);

	double d = logcycle - (logcumcycle + log(w) + log(h));
	if(d <= 0) puts("Slideshow");
	else if(fabs(d - log60) < EPS || d > log60) puts("Perfect");
	else if(d < log10) puts("Slideshow");
	else puts("So-so");

	for(int i=0; i<m; ++i)
	{
		scanf(" %s", op);
		if(strcmp(op, "Off") == 0) 
		{
			scanf(" %s", op);
			logcumcycle -= log(dic[op]);
		}
		else if(strcmp(op, "On") == 0)
		{
			scanf(" %s", op);
			logcumcycle += log(dic[op]);
		}
		else if(strcmp(op, "Resolution") == 0)
			scanf("%d %d", &w, &h);
		
		double d = logcycle - (logcumcycle + log(w) + log(h));
		//printf("logcycle= %lf, logcumcycle= %lf, d= %lf, log60= %lf, log10= %lf\n", logcycle, logcumcycle, d, log60, log10);
		if(d <= 0) puts("Slideshow");
		else if(fabs(d - log60) < EPS || d > log60) puts("Perfect");
		else if(d < log10) puts("Slideshow");
		else puts("So-so");
	}

	return 0;
}
