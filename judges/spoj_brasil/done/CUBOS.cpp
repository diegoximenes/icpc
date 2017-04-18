#include<cstdio>
#include<set>
#include<vector>
using namespace std;

#define pb push_back

set<vector<int> > dicRotation;
set<vector<int> > dic;

bool rotateRight(vector<int> cube);
bool rotateUp(vector<int> cube);

bool rotateRight(vector<int> cube)
{
	vector<int> rotated;
	rotated.pb(cube[1]);
	rotated.pb(cube[5]);
	rotated.pb(cube[2]);
	rotated.pb(cube[0]);
	rotated.pb(cube[4]);
	rotated.pb(cube[3]);

	if(dicRotation.find(rotated) == dicRotation.end())
	{
		if(dic.find(rotated) != dic.end())
			return 0;
		dicRotation.insert(rotated);
		return rotateUp(rotated) && rotateRight(rotated);
	}
	return 1;
}

bool rotateUp(vector<int> cube)
{
	vector<int> rotated;
	rotated.pb(cube[0]);
	rotated.pb(cube[4]);
	rotated.pb(cube[1]);
	rotated.pb(cube[2]);
	rotated.pb(cube[3]);
	rotated.pb(cube[5]);

	if(dicRotation.find(rotated) == dicRotation.end())
	{
		if(dic.find(rotated) != dic.end())
			return 0;
		dicRotation.insert(rotated);
		return rotateUp(rotated) && rotateRight(rotated);
	}
	return 1;
}

int main()
{
	int n, c;

	while(scanf("%d", &n) && n)
	{
		dic.clear();

		for(int i=0; i<n; ++i)
		{
			vector<int> cube;
			for(int j=0; j<6; ++j)
			{
				scanf("%d", &c);
				cube.pb(c);
			}
			
			if(dic.find(cube) != dic.end()) continue;
			dicRotation.clear();
			dicRotation.insert(cube);
			if(rotateRight(cube) && rotateUp(cube))
				dic.insert(cube);
		}
		printf("%d\n", dic.size());
	}

	return 0;
}
