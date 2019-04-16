#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast_io ios::sync_with_stdio(false)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL
const double PI = acos(-1);
const double EPS = 1e-9;

inline int cmp_double(double x, double y, double tol = EPS) {
    // (x < y): -1, (x == y): 0, (x > y): 1
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

#define MAX 1005
#define MAXL ('Z' - 'A' + 1)

char s[MAX];

class Node {
    public:
        vector<Node*> childs;
        int cnt;
        Node() {
            childs.assign(MAXL, NULL);
            cnt = 0;
        }
};

void add(Node *node, int i) {
    if (i < 0) {
        return;
    }
    int pos = s[i] - 'A';
    if (node->childs[pos] == NULL) {
        node->childs[pos] = new Node();
    }
    node->childs[pos]->cnt++;
    add(node->childs[pos], i - 1);
}

void free(Node *node) {
    for (int i = 0; i < MAXL; ++i) {
        if (node->childs[i] != NULL) {
            free(node->childs[i]);
        }
    }
    delete node;
}

int dfs(Node *node) {
    int ret = 0;

    if (node->cnt == 1) {
        ret = 0;
    } else if (node->cnt == 2) {
        ret = 2;
    } else {
        int cnt_dfs_childs = 0;
        for (int i = 0; i < MAXL; ++i) {
            if (node->childs[i] != NULL) {
                cnt_dfs_childs += dfs(node->childs[i]);
            }
        }

        if (node->cnt - cnt_dfs_childs >= 2) {
            ret = cnt_dfs_childs + 2;
        } else {
            ret = cnt_dfs_childs;
        }
    }
    return ret;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int tc = 1; tc <= t; ++tc) {
        int n;
        scanf("%d", &n);

        Node *trie = new Node();
        for (int i = 0; i < n; ++i) {
            scanf(" %s ", s);
            add(trie, strlen(s) - 1);
        }

        int sol = 0;
        for (int i = 0; i < MAXL; ++i) {
            if (trie->childs[i] != NULL) {
                sol += dfs(trie->childs[i]);
            }
        }
        free(trie);

        printf("Case #%d: %d\n", tc, sol);
    }

    return 0;
}
