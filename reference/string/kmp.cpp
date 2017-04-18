#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAX 2005

char p[MAX], t[MAX];
int pi_[MAX];

void kmp_prefix() {
    int m = strlen(p);
    pi_[0] = -1;
    for (int i = 1, k = -1; i < m; ++i) {
        while (k >= 0 && p[k + 1] != p[i]) k = pi_[k];
        if (p[k + 1] == p[i]) ++k;
        pi_[i] = k;
    }
}

void kmp_matcher() {
    int m = strlen(p), n = strlen(t);
    for (int i = 0, k = -1; i < n; ++i) {
        while (k >= 0 && p[k + 1] != t[i]) k = pi_[k];
        if (p[k + 1] == t[i]) ++k;
        if (k + 1 == m) {
            // match found at i - k
            k = pi_[k];
        }
    }
}
