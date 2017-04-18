#include<cstdio>
#include<map>
#include<cstring>
#include<string>
using namespace std;

int main()
{
	map<string, int> dic;
	char medal[10], uni[10000];
	int guess, maxGuess, countGuess, n, k, ind;

	maxGuess = 0; countGuess = 0;
	for(int i=0; i<12; ++i)
	{
		scanf(" %s", uni);
		dic[uni] = i/4;
	}
	scanf("%d", &n);
	for(int i=0; i<n; ++i)
	{
		scanf("%d", &k);
		guess = 0;
		for(int j=0; j<k; ++j)
		{
			scanf(" %s : %s", uni, medal);
			if(strcmp(medal, "gold") == 0) ind = 0;
			else if(strcmp(medal , "silver") == 0) ind = 1;
			else ind = 2;

			if(dic.find(uni) != dic.end() && dic[uni] == ind)
				++guess;
		}
		if(guess > maxGuess)
		{
			maxGuess = guess;
			countGuess = 1;
		}
		else if(guess == maxGuess)
			++countGuess;
	}
	printf("%d\n", countGuess*5);

	return 0;
}
