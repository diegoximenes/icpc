#include<cstdio>
#include<cstring>
#include<map>
using namespace std;

#define mp make_pair
#define MAX 25

int countStates, state[MAX][MAX];
pair<int, int> stateList[MAX*MAX];
double p[MAX][MAX];

void buildState(int ev1, int ev2, int d)
{
	if(ev1 <= 0 || ev2 <= 0 || state[ev1][ev2] != -1) return;
	
	stateList[countStates] = mp(ev1, ev2);
	state[ev1][ev2] = countStates++;

	buildState(ev1 - d, ev2 + d, d);
	buildState(ev1 + d, ev2 - d, d);
}

void mul(double a[MAX][MAX], double b[MAX][MAX], int n, double c[MAX][MAX])
{
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			for(int k=c[i][j]=0; k<n; ++k)
				c[i][j] += a[i][k]*b[k][j];
}

void exp(double p[MAX][MAX], int e, int n, double res[MAX][MAX])
{ 
	double temp[MAX][MAX];

	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			res[i][j] = (i == j);
	
	if(e == 0) return;

	exp(p, e/2, n, temp);
	mul(temp, temp, n, res);
	if(e%2 != 0)
	{
		mul(p, res, n, temp);
		memcpy(res, temp, sizeof(temp));
	}
}

int main()
{
	int ev1, ev2, d, w1, w2;
	double at, estationary[MAX][MAX];

	while(scanf("%d %d %lf %d", &ev1, &ev2, &at, &d) && ev1)
	{
		countStates = 0;
		memset(state, -1, sizeof(state));

		buildState(ev1, ev2, d);
		w1 = countStates; w2 = w1 + 1;
		
		memset(p, 0, sizeof(p));
		for(int i=0; i<countStates; ++i)
		{
			pair<int, int> st = stateList[i];
			int stId = state[st.first][st.second];

			if(st.first - d <= 0) p[stId][w2] = (6.0 - at)/6.0;
			else p[stId][state[st.first - d][st.second + d]] = (6.0 - at)/6.0;

			if(st.second - d <= 0) p[stId][w1] = at/6.0;
			else p[stId][state[st.first + d][st.second - d]] = at/6.0;
		}
		p[w1][w1] = p[w2][w2] = 1.0;
		
		int inf = 610;
		exp(p, inf, w2, estationary);
		printf("%.1lf\n", 100.0*estationary[0][w1]);
	}

	return 0;
}

