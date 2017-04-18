#include<cstdio>
#include<queue>
#include<map>
#include<stack>
using namespace std;

#define MAX 1010

int main()
{
	pair<int, int> state;
	int n, ca, cb, a, b, aaux, baux;
	bool mark[MAX][MAX];
	vector< vector< pair<int, int> > > dad;
	
	dad.resize(MAX);
	for(int i=0; i<MAX; ++i)
		dad[i].resize(MAX);
	
	while(scanf("%d %d %d", &ca, &cb, &n) == 3)
	{
		queue< pair<int,int> > f;		
		
		for(int i=0; i<=ca; ++i)
			for(int j=0; j<=cb; ++j)
				mark[i][j] = 0;
		
		f.push(make_pair(0, 0));
		mark[0][0] = 1;
		dad[0][0] = make_pair(0, 0);
		
		while(!f.empty())
		{
			state = f.front();
			f.pop();

			if(state.second == n)
			{
				a = state.first;
				b = state.second;
				
				break;
			}
			
			if(state.first < ca) //fill jug a
				if(!mark[ca][state.second])
				{
					mark[ca][state.second] = 1;
					dad[ca][state.second] = make_pair(state.first, state.second);
					
					f.push(make_pair(ca, state.second));
				}
			if(state.second < cb) //fill jug b
				if(!mark[state.first][cb])
				{
					mark[state.first][cb] = 1;
					dad[state.first][cb] = make_pair(state.first, state.second);
					
					f.push(make_pair(state.first, cb));
				}
			if(state.first > 0) //empty jug a
			{
				if(!mark[0][state.second])
				{
					mark[0][state.second] = 1;
					dad[0][state.second] = make_pair(state.first, state.second);
					
					f.push(make_pair(0, state.second));
				}
			}
			if(state.second > 0) //empty jug b
			{
				if(!mark[state.first][0])
				{
					mark[state.first][0] = 1;
					dad[state.first][0] = make_pair(state.first, state.second);
					
					f.push(make_pair(state.first, 0));
				}
			}
			if(state.first > 0 && state.second < cb) //pour a b
			{
				if(state.first + state.second <= cb)
				{
					if(!mark[0][state.first + state.second])
					{
						mark[0][state.first + state.second] = 1;
						dad[0][state.first + state.second] = make_pair(state.first, state.second);
						
						f.push(make_pair(0 , state.first + state.second));
					}
				}
				else
				{
					if(!mark[state.first - (cb - state.second)][cb])
					{
						mark[state.first - (cb - state.second)][cb] = 1;
						dad[state.first - (cb - state.second)][cb] = make_pair(state.first, state.second);
						
						f.push(make_pair(state.first - (cb - state.second) , cb));
					}
				}
			}
			if(state.second > 0 && state.first < ca) //pour b a
			{
				if(state.first + state.second <= ca)
				{
					if(!mark[state.first + state.second][0])
					{
						mark[state.first + state.second][0] = 1;
						dad[state.first + state.second][0] = make_pair(state.first, state.second);
						
						f.push(make_pair(state.first + state.second, 0));
					}
				}
				else
				{
					if(!mark[ca][state.second - (ca - state.first)])
					{
						mark[ca][state.second - (ca - state.first)] = 1;
						dad[ca][state.second - (ca - state.first)] = make_pair(state.first, state.second);
						
						f.push(make_pair(ca, state.second - (ca - state.first)));
					}
				}
			}
		}
		
		stack< pair<int, int> > p;
		while(1)
		{
			p.push(make_pair(a, b));
			
			if((a==0) && (b==0))
				break;
			
			aaux = dad[a][b].first;
			baux = dad[a][b].second;
			
			a = aaux;
			b = baux;
		}
		
		a = p.top().first;
		b = p.top().second;
		p.pop();
		while(!p.empty())
		{
			aaux = p.top().first;
			baux = p.top().second;
			p.pop();
			//printf("%d %d\n", a, b);
			//printf("%d %d\n", aaux, baux);
			
			if((aaux == 0) && (baux == b))
				puts("empty A");
			else if((baux == 0) && (aaux == a))
				puts("empty B");
			else if((aaux == ca) && (baux == b))
				puts("fill A");
			else if((baux == cb) && (aaux == a))
				puts("fill B");
			else if((aaux > a) && (baux < b))
				puts("pour B A");
			else if((baux > b) && (aaux < a))
				puts("pour A B");
			
			a = aaux;
			b = baux;
		}
		puts("success");
	}
	
	return 0;
}