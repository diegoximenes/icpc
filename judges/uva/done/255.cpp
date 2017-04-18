#include<cstdio>
#include<algorithm>
#include<utility>
using namespace std;

#define mp make_pair

inline pair<int, int> pos(int id)
{
	return mp(id/8, id%8);
}

inline int id(pair<int, int> pos)
{
	return pos.first*8 + pos.second;
}

inline bool can(int i, int j)
{
	if(i>=0 && i<8 && j>=0 && j<8) return 1;
	return 0;
}

int main()
{	
	int q, k, nq;

	while(scanf("%d %d %d", &k, &q, &nq) == 3)
	{
		pair<int, int> kpos = pos(k), qpos = pos(q), nqpos = pos(nq);

		if(q == k) puts("Illegal state");
		else if((q == nq) || (qpos.first != nqpos.first && qpos.second != nqpos.second) || (nq == k) || (nqpos.first == qpos.first && kpos.first == nqpos.first && kpos.second > min(qpos.second, nqpos.second) && kpos.second < max(qpos.second, nqpos.second)) || (nqpos.second == qpos.second && kpos.second == nqpos.second && kpos.first > min(qpos.first, nqpos.first) && kpos.first < max(qpos.first, nqpos.first))) 
			puts("Illegal move");
		else if ((can(kpos.first+1, kpos.second) && nq == id(mp(kpos.first+1, kpos.second))) || (can(kpos.first-1, kpos.second) && nq == id(mp(kpos.first-1, kpos.second))) || (can(kpos.first, kpos.second+1) && nq == id(mp(kpos.first, kpos.second+1))) || (can(kpos.first, kpos.second-1) && nq == id(mp(kpos.first, kpos.second-1))))
			puts("Move not allowed");
		else if((can(kpos.first+1, kpos.second) && kpos.first + 1 != nqpos.first && kpos.second != nqpos.second) || (can(kpos.first-1, kpos.second) && kpos.first - 1 != nqpos.first && kpos.second != nqpos.second) || (can(kpos.first, kpos.second+1) && kpos.second + 1 != nqpos.second && kpos.first != nqpos.first) || (can(kpos.first, kpos.second-1) && kpos.second - 1 != nqpos.second && kpos.first != nqpos.first))
			puts("Continue");
		else puts("Stop");
	}

	return 0;
}
