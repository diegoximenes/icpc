/*
O(n + m + z), n == size of concatenation of patterns, m == size of text,
z number of pattern occurrences in the text
Tested with: I Love Strings(uva 10679)
*/

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define MAXL 60
#define MAXT 100010
#define MAXLENP 1010
#define MAXP 1010

char t[MAXT], p[MAXLENP];

int count_vertexes_;

struct Vertex {
    Vertex *letter[MAXL];
    int id;

    Vertex() {
        for (int i = 0; i < MAXL; ++i) letter[i] = NULL;
        id = count_vertexes_++;
    }
};

Vertex *failure_[MAXP * MAXLENP];
bool mark_[MAXP * MAXLENP], match_[MAXP];
vector<int> out_[MAXP * MAXLENP];

void insert(Vertex *v, char *w, int len, int id_pattern) {
    if (v->letter[*w - 'A'] == NULL) v->letter[*w - 'A'] = new Vertex();
    if (len == 1)
        out_[v->letter[*w - 'A']->id].pb(id_pattern);
    else
        insert(v->letter[*w - 'A'], w + 1, len - 1, id_pattern);
}

void free_mem(Vertex *v) {
    for (int i = 0; i < MAXL; ++i)
        if (v->letter[i] != NULL && v->letter[i] != v)
            free_mem(v->letter[i]);
    delete v;
}

void create_failure_edges(Vertex *root) {
    queue<Vertex*> q;
    Vertex *u, *v;

    memset(mark_, 0, sizeof(mark_));
    for (int i = 0; i < MAXL; ++i)
        if (root->letter[i] == NULL)
            root->letter[i] = root;

    failure_[root->id] = root;
    for (int i = 0; i < MAXL; ++i)
        if (root->letter[i] != NULL && !mark_[root->letter[i]->id]) {
            q.push(root->letter[i]);
            mark_[root->letter[i]->id] = 1;
            failure_[root->letter[i]->id] = root;
        }

    while (!q.empty()) {
        v = q.front(); q.pop();
        for (int i = 0; i < MAXL; ++i) {
            if (v->letter[i] != NULL && !mark_[v->letter[i]->id]) {
                q.push(v->letter[i]);
                mark_[v->letter[i]->id] = 1;
                u = failure_[v->id];
                while (u->letter[i] == NULL) u = failure_[u->id];
                failure_[v->letter[i]->id] = u->letter[i];
                for (int j = 0;
                     j < (int) out_[failure_[v->letter[i]->id]->id].size();
                     ++j) {
                    out_[v->letter[i]->id].pb(
                        out_[failure_[v->letter[i]->id]->id][j]);
                }
            }
        }
    }
}

void search(Vertex *v) {
    int len = strlen(t);
    for (int i = 0; i < len; ++i) {
        while (v->letter[t[i]-'A'] == NULL) v = failure_[v->id];
        v = v->letter[t[i]-'A'];
        if (!out_[v->id].empty()) {
            for (int j = 0; j < (int) out_[v->id].size(); ++j)
                match_[out_[v->id][j]] = 1;
            // found out_[v->id] patterns at position i
        }
    }
}

void init() {
    memset(match_, 0, sizeof(match_));
    for (int i = 0; i < MAXP * MAXLENP; ++i) out_[i].clear();
}

int main() {
    int tc, q;
    Vertex *v;

    scanf("%d", &tc);
    while (tc--) {
        scanf(" %s %d", t, &q);

        v = new Vertex();
        init();
        for (int i = 0; i < q; ++i) {
            scanf(" %s", p);
            insert(v, p, strlen(p), i);
        }
        create_failure_edges(v);
        search(v);

        for (int i = 0; i < q; ++i) puts(match_[i] ? "y" : "n");

        free_mem(v);
    }

    return 0;
}
