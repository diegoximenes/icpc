#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
using namespace std;

#define MAXL 26

struct Vertex {
    Vertex *letter[MAXL];
    int count;
    bool end; //end == 1 if this letter is the end of a word

    Vertex() {
        for (int i = 0; i < MAXL; ++i) letter[i] = NULL;
        count = end = 0;
    }
};

void insert(Vertex *v, char *w, int len) {
    if (v->letter[*w - 'a'] == NULL) {
        v->letter[*w - 'a'] = new Vertex;
        ++v->count;
    }
    if (len == 1)
        v->letter[*w - 'a']->end = 1;
    else
        insert(v->letter[*w - 'a'], w + 1, len - 1);
}

void free_mem(Vertex *v)
{
    for(int i=0; i<MAXL; ++i)
        if(v->letter[i] != NULL)
            free_mem(v->letter[i]);
    delete v;
}

int key_strokes(Vertex *v, string str, int ind)
{
    if (ind == (int)str.size()) return 0;
    if (v->count == 1) {
        for(int i=0; i<MAXL; ++i) {
            if(v->letter[i] != NULL) {
                int ret = key_strokes(v->letter[i], str, ind + 1);
                ret += (v->end ? 1 : 0);
                return ret;
            }
        }
    } else {
        return 1 + key_strokes(v->letter[str[ind] - 'a'], str, ind+1);
    }
}

int main()
{
    int n, len;
    char word[100];
    vector<string> dic;

    while (gets(word) != NULL) {
        Vertex *v = new Vertex;
        dic.clear();
        sscanf(word, "%d", &n);
        while (n--) {
            gets(word);
            len = strlen(word);
            dic.push_back(word);
            insert(v, word, len);
        }

        int count = 0;
        for (int i = 0; i < (int) dic.size(); ++i)
            count += 1 + key_strokes(v->letter[dic[i][0] - 'a'], dic[i], 1);
        printf("%.2lf\n", (double) count / (double) dic.size());

        free_mem(v);
    }

    return 0;
}
