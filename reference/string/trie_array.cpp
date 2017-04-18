/*
Tested with: live archive 6133
*/
#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define LMAX ('z'-'a'+1)
#define NMAX 500005 //max number of vertexes, think how to guess this number

int trie_[NMAX][LMAX], nv_;
bool is_end_[NMAX]; //1 if this vertex is a word end

inline int ind(char c) {
    return (c - 'a');
}

void insert(char *s) {
    int len = strlen(s), u = 0;
    for (int i = 0; i < len; ++i) {
        if (trie_[u][ind(s[i])] == -1) trie_[u][ind(s[i])] = ++nv_;
        u = trie_[u][ind(s[i])];
    }
    is_end_[u] = 1;
}

int key_strokes(int u, int i, string &s) {
    if (i == (int) s.size()) return 0;

    int cnt_child = 0;
    for (int j = 0; j < LMAX; ++j)
        if (trie_[u][j] != -1)
            ++cnt_child;

    int sol = key_strokes(trie_[u][ind(s[i])], i + 1, s);
    if (cnt_child > 1 || is_end_[u]) sol++;
    return sol;
}


void init() {
    nv_ = 0;
    memset(is_end_, 0, sizeof(is_end_));
    memset(trie_, -1, sizeof(trie_));
}

char word[NMAX];

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        init();

        vector<string> v;
        while (n--) {
            scanf(" %s ", word);
            v.pb(word);
            insert(word);
        }

        int cnt = 0;
        for (int i = 0; i < (int) v.size(); ++i)
            cnt += 1 + key_strokes(trie_[0][ind(v[i][0])], 1, v[i]);
        printf("%.2lf\n", (double) cnt / (double) v.size());
    }

    return 0;
}
