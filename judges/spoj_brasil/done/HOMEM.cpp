#include<cstdio>
#include<cstring>
using namespace std;

#define MAX 300010

struct State
{
	bool h, e, r;
};

State tree[MAX];
int helper[MAX], n;

void init()
{
	for(int i=0; i<MAX; ++i)
	{
		tree[i].e = tree[i].r = helper[i] = 0;
		tree[i].h = 1;
	}
}

void update(int node, int start, int end, int left, int right)
{
	if(left>end || right<start)
		return;
	if(start == end)
	{
		tree[node] += state1;
		tree[node] += state1*helper[node];
		helper[node] = 0;
		return;
	}
	if(left<=start && right>=end)
	{
		++helper[2*node];
		++helper[2*node+1];
		tree[node] += state1*(end-start+1);
		return;
	}
	else if(left<=end && right>end)
		tree[node] += state1*(end-left+1);
	else if(start<=right && left<start)
		tree[node] += state1*(right-start+1);
	else if(left>=start && right<=end)
		tree[node] += state1*(right-left+1);

	update(2*node, start, (start+end)/2, left, right);
	update(2*node+1, (start+end)/2+1, end, left, right);
}

State query(int node, int start, int end, int left, int right)
{
	if(left>end || right<start)
		return state0;
	if(helper[node] != 0)
	{
		tree[node] += state1*(helper[node]*(end-start+1));
		if(start != end)
		{
			helper[2*node] += helper[node];
			helper[2*node+1] += helper[node];
		}
		helper[node] = 0;
	}
	if(left<=start && right>=end)
		return tree[node];
	
	State s1, s2;
	s1 = query(2*node, start, (start+end)/2, left, right);
	s2 = query(2*node+1, (start+end)/2+1, end, left, right);
	return s1+s2;
}

State query(int l, int r)
{
	return query(1, 1, n, l, r);
}

void update(int l, int r)
{
	update(1, 1, n, l, r);
}

int main()
{
	int m, l, r;
	char line[100], op;
	State st;

	while(gets(line))
	{
		sscanf(line, "%d %d", &n, &m);
		init();
		while(m--)
		{
			gets(line);
			sscanf(line, "%c %d %d", &op, &l, &r);
			if(op == 'M')
				update(l, r);
			else
			{
				st = query(l, r);
				printf("%d %d %d\n", st.h, st.e, st.r);
			}
		}
	}

	return 0;
}
