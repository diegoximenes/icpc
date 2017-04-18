#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
using namespace std;

#define INF 1e9
#define mp make_pair
#define pb push_back

const int n = 3, upper = 9;
int exp10[10];

inline int id(int i, int j) { return (i*n + j); }
inline pair<int, int> pos(int d) { return mp(d/n, d%n); }

inline void setDigit(int &num, int pos, int digit) 
{
	num += exp10[pos] * digit;
}

inline int fromVecToInt(vector<int> &v)
{
	int ret = 0;
	for(int i=0; i<(int)v.size(); ++i) setDigit(ret, i, v[i]);
	return ret;
}

inline vector<int> getDigits(int num)
{
	vector<int> v;
	for(int i=0; i<upper; ++i)
	{
		v.pb(num % 10);
		num /= 10;
	}
	return v;
}

inline int left(int d)
{
	pair<int, int> p = pos(d);
	int i = p.first, j = p.second;

	if(j >= 1) return id(i, j-1);
	
	--i; j = n-1;
	if(i < 0) i = n-1;	
	return id(i, j);
}
inline int right(int d)
{
	pair<int, int> p = pos(d);
	int i = p.first, j = p.second;

	if(j <= 1) return id(i, j+1);
	
	++i; j = 0;
	if(i == n) i = 0;	
	return id(i, j);
}
inline int top(int d)
{
	pair<int, int> p = pos(d);
	int i = p.first, j = p.second;

	if(i >= 1) return id(i-1, j);
	return id(n-1, j);
}
inline int bottom(int d)
{
	pair<int, int> p = pos(d);
	int i = p.first, j = p.second;

	if(i <= 1) return id(i+1, j);
	return id(0, j);
}

int main()
{	
	int ch, cv, x;
	
	exp10[0] = 1;
	for(int i=1; i<=9; ++i) exp10[i] = 10*exp10[i-1];

	while(scanf("%d %d", &ch, &cv) && ch)
	{
		int s = 0, t = 0; 
		for(int i=0; i<upper; ++i) scanf("%d", &x), setDigit(s, i, x);
		for(int i=0; i<upper; ++i) scanf("%d", &x), setDigit(t, i, x);
		
		set<int> mark1, mark2;
		set< pair<int, int> > heap1, heap2;
		map<int, int> dist1, dist2;
		map<int, int>::iterator it;
		heap1.insert(mp(0, s)); dist1[s] = 0;
		heap2.insert(mp(0, t)); dist2[t] = 0;
		int turn = 0, sol = INF;
		for(; 1; turn=1-turn)
		{
			int iu;
			if(!turn)
			{
				iu = heap1.begin()->second;
				heap1.erase(heap1.begin());
				mark1.insert(iu);
		
				if(mark2.find(iu) != mark2.end()) break;
			}
			else
			{
				iu = heap2.begin()->second;
				heap2.erase(heap2.begin());
				mark2.insert(iu);
		
				if(mark1.find(iu) != mark1.end()) break;
			}
				
			vector<int> u = getDigits(iu);
			
			for(int i=0; i<upper; ++i)
				if(u[i] == 0)
				{
					vector< pair< vector<int> , int> > aux;
					vector<int> v;
					
					v = u;
					v[i] = u[left(i)];
					v[left(i)] = 0;
					aux.pb(mp(v, ch));

					v = u;
					v[i] = u[right(i)];
					v[right(i)] = 0;
					aux.pb(mp(v, ch));

					v = u;
					v[i] = u[top(i)];
					v[top(i)] = 0;
					aux.pb(mp(v, cv));

					v = u;
					v[i] = u[bottom(i)];
					v[bottom(i)] = 0;
					aux.pb(mp(v, cv));

					for(int k=0; k<4; ++k)
					{
						v = aux[k].first;
						int d = aux[k].second;
						
						int iv = fromVecToInt(v);
						
						if(!turn)
						{
							if((mark1.find(iv) == mark1.end()))
							{
								int distv = INF;
								if(dist1.find(iv) != dist1.end()) distv = dist1[iv];
								
								if(distv > dist1[iu] + d)
								{
									heap1.erase(mp(distv, iv));
									dist1[iv] = dist1[iu] + d;
									heap1.insert(mp(dist1[iv], iv));
								}
							}
						}
						else
						{
							if((mark2.find(iv) == mark2.end()))
							{
								int distv = INF;
								if(dist2.find(iv) != dist2.end()) distv = dist2[iv];
								
								if(distv > dist2[iu] + d)
								{
									heap2.erase(mp(distv, iv));
									dist2[iv] = dist2[iu] + d;
									heap2.insert(mp(dist2[iv], iv));
								}
							}
						}
					}

					break;
				}
		}
		
		int sol = INF;
		for(it=dist1.begin(); it!=dist1.end(); ++it)
			if(dist2.find(it->first) != dist2.end())
				sol = min(sol, it->second + dist2[it->first]);
		printf("%d\n", sol);
	}

	return 0;
}
