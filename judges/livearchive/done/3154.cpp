#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define MAXFACE 13
#define MAXSUIT 4

map<char, int> dicSuit, dicFace;

struct Card
{
    char face, suit;

    Card(char face=0, char suit=0) : face(face), suit(suit) {} ;
    
    bool operator<(Card o) const
    {
        if(suit != o.suit) return dicSuit[suit] < dicSuit[o.suit];
        return dicFace[face] < dicFace[o.face];
    }

    bool operator==(const Card &o) const
    {
        if(face != o.face) return 0;
        if(suit != o.suit) return 0;
        return 1;
    }
};

int main()
{
    map<char, int>::iterator it;
    map<int, char> dicSuit2, dicFace2;
    
    dicSuit['H'] = 0;
    dicSuit['C'] = 1;
    dicSuit['D'] = 2;
    dicSuit['S'] = 3;
    for(char c='0'; c<='9'; ++c) dicFace[c] = c - '0';
    dicFace['T'] = 10;
    dicFace['J'] = 11;
    dicFace['Q'] = 12;
    dicFace['K'] = 13;
    
    for(it = dicSuit.begin(); it!=dicSuit.end(); ++it) dicSuit2[it->second] = it->first;
    for(it = dicFace.begin(); it!=dicFace.end(); ++it) dicFace2[it->second] = it->first;
    
    int t;
    scanf("%d", &t);

    int outFace = - 1, outSuit = - 1;
    string c0, c1, c2, c3;
    while(t--)
    {
        cin >> c0 >> c1 >> c2 >> c3;

        outFace = dicFace[c0[0]];
        outSuit = dicSuit[c0[1]];
       
        /*for(int i=0; i<4; ++i)
        {
            cards.pb(Card(in[i][1], in[i][0]));
            hasCard[dicSuit[in[i][1]]][dicFace[in[i][0]]] = 1;
            cntSuit[dicSuit[in[i][1]]]++;
        }
        
        int outFace = -1, outSuit = -1;
        for(int i=0; outFace == -1 && i<MAXSUIT; ++i)
            if(cntSuit[i] >= 2)
            {
                for(int j=0; outFace == -1 && j<MAXFACE; ++j)
                    if(hasCard[i][j])
                        for(int k=1; k<=6; ++k)
                        {
                            int j2 = j - k;
                            if(j2 < 0) j2 += MAXFACE;

                            if(hasCard[i][j2])
                            {
                                outFace = j2;
                                outSuit = i;
                            }
                      }
            }*/
        
        //cout << "c= " << endl << c0 << " " << c1 << " " << c2 << " " << c3 << endl;


        vector<Card> cards, sortedCards;
        cards.pb(Card(c1[0], c1[1]));
        cards.pb(Card(c2[0], c2[1]));
        cards.pb(Card(c3[0], c3[1]));
        sortedCards = cards;
        sort(sortedCards.begin(), sortedCards.end());
        
        vector<Card> lcards = cards;
        vector<int> perm;
        for(int i=0; i<3; ++i) perm.pb(i);
        
        //printf("cards= ");
        //for(int i=0; i<3; ++i) printf("%c%c ", cards[i].face, cards[i].suit);
        //puts("");
        
        int cnt = 0;
        do
        {
            cnt++;
            
            for(int i=0; i<(int)perm.size(); ++i)
                lcards[i] = sortedCards[perm[i]];
            
            //printf("lcards= ");
            //for(int i=0; i<(int)perm.size(); ++i) printf("%c%c ", lcards[i].face, lcards[i].suit);
            //puts("");

            if(cards == lcards) break;
            
        }while(next_permutation(perm.begin(), perm.end()));
        
       // printf("outFace= %d, cnt= %d\n", outFace, cnt);

        outFace += cnt;
        if(outFace > MAXFACE) outFace -= MAXFACE;

        //printf("outFace= %d, cnt= %d\n", outFace, cnt);

        printf("%c%c\n", dicFace2[outFace], dicSuit2[outSuit]);
        
    }

    return 0;
}
