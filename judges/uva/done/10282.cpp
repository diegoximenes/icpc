//18:34
#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
#include<map>
using namespace std;

int main()
{
    map<string, string> m;
    map<string, string>::iterator it;
    char w1[11], w2[11];
    char c;
    string sw1, sw2;
    
    while(1)
    {
	memset(w1, 0, 11);
	memset(w2, 0, 11);
	
	//cout << "1: sw1 = " << sw1 << ", sw2 = " << sw2 << ", w1 = " << w1 << ", w2 = " << w2 << endl;
	
	for(int i=0; ;i++)
	{
	    scanf("%c", &c);
	    if((c == ' ') || (c == '\n'))
		break;
	    else
		w1[i] = c;
	}
	
	if(c == ' ')
	{
	    for(int i=0; ;i++)
	    {
		scanf("%c", &c);
		if(c == '\n')
		    break;
		else
		    w2[i] = c;
	    }
	    
	    sw1 = w1;
	    sw2 = w2;
	    
	    //cout << "2: sw1 = " << sw1 << ", sw2 = " << sw2 << ", w1 = " << w1 << ", w2 = " << w2 << endl;
	    
	    it = m.find(sw2);
	    if(it == m.end())
		m[sw2] = sw1;
	}
	else
	{
	    int i = 0;
	    while(scanf("%s", w2) != EOF)
	    {
		sw2 = w2;
		
		 it = m.find(sw2);
		 if(it == m.end())
		    cout << "eh\n";
		else
		    cout << it->second << endl;
	    }
	    break;
	}
    }
    return 0;
}