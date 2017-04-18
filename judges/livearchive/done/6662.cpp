#include<cstdio>
#include<vector>
using namespace std;

#define mp make_pair
#define pb push_back

struct Node
{
	int id, pos;
	char d;
	Node(int id=0, int pos=0, char d=' ') : id(id), pos(pos), d(d) {}
};

int main()
{
	vector<Node> v;
	int n, l;

	while(scanf("%d %d", &n, &l) && n)
	{
		for(int i=0; i<n; ++i)
		{
			int p; char d;
			scanf(" %c %d", &d, &p);
			v.pb(Node(i, p, d));
		}
		
		int t = 0, last;
		for(; !v.empty(); ++t)
		{
			n = v.size();
			
			//printf("t= %d\n", t);
			//for(int i=0; i<n; ++i) printf("(%d, %d, %c)\n", v[i].id, v[i].pos, v[i].d);
			//puts("\n");

			vector<Node> v2;
			last = -1;
			for(int i=0; i<n; ++i)
			{
				if(v[i].pos == l && v[i].d == 'R')
				{
					if(last == -1) last = v[i].id;
					continue;
				}
				else if(v[i].pos == 0 && v[i].d == 'L')
				{
					last = v[i].id;
					continue;
				}

				v2.pb(v[i]);
			}
			
			v = v2;
			n = v.size();
			for(int i=0; i<n; ++i)
				for(int j=i+1; j<n; ++j)
					if(v[i].pos == v[j].pos)
						swap(v[i].d, v[j].d);
			
			for(int i=0; i<n; ++i)
			{
				if(v[i].d == 'R') v[i].pos++;
				else v[i].pos--;
			}
		}

		printf("%d %d\n", t-1, last+1);
	}
	

	return 0;
}
