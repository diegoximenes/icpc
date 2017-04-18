#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

#define pb push_back
#define mp make_pair

bool cmp(pair<int, string> p1, pair<int, string> p2)
{
	if(p1.first != p2.first) return p1.first > p2.first;
	return p1.second < p2.second;
}

int main()
{
	char word[50];
	int top, pos = -1;
	map<string, int> dic[10];
	map<string, int>::iterator it;

	while(scanf(" %s", word) == 1)
	{
		if(strcmp(word, "<text>") == 0) pos = (pos+1)%7, dic[pos].clear();
		else if(strcmp(word, "<top") == 0)
		{
			scanf("%d %*s", &top);
			
			map<string, int> cnt;
			vector< pair<int, string> > v;
			for(int i=0; i<7; ++i)
			{
				int actual = pos-i;
				if(actual < 0) actual += 7;
				for(it=dic[actual].begin(); it!=dic[actual].end(); ++it)
				{
					if(cnt.find(it->first) == cnt.end()) cnt[it->first] = it->second;
					else cnt[it->first] += it->second;
				}
			}
			for(it=cnt.begin(); it!=cnt.end(); ++it) v.pb(mp(it->second, it->first));
			
			printf("<top %d>\n", top);
			sort(v.begin(), v.end(), cmp);
			int last = v.front().first;
			printf("%s %d\n", v.front().second.c_str(), v.front().first);
			top--;
			for(int i=1; i<(int)v.size(); ++i)
			{
				if(top <= 0 && v[i].first != last) break;
				printf("%s %d\n", v[i].second.c_str(), v[i].first);
				last = v[i].first;
				top--;
			}
			printf("</top>\n");
		}
		else if(strcmp(word, "</text>") != 0 && strlen(word) >= 4)
		{
			if(dic[pos].find(word) == dic[pos].end()) dic[pos][word] = 1;
			else dic[pos][word]++;
		}

	}

	return 0;
}
