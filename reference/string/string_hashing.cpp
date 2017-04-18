#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define MAX 600005

char str[MAX];

const ll B = 33;
const ll MOD1 = 1000000007LL, MOD2 = 1000000009LL;

ll pow_b1_[MAX], pow_b2_[MAX];
ll hash1_[MAX], hash2_[MAX];

void calc_base_pow() {
    pow_b1_[0] = pow_b2_[0] = 1;
    for (int i = 1; i < MAX; ++i) {
        pow_b1_[i] = (B * pow_b1_[i - 1]) % MOD1;
        pow_b2_[i] = (B * pow_b2_[i - 1]) % MOD2;
    }
}

void calc_hash(char *str)
{
    int len = strlen(str);
    hash1_[len] = hash2_[len] = 0;
    for (int i = len - 1; i >= 0; --i) {
        hash1_[i] = (str[i] + (B * hash1_[i + 1]) % MOD1) % MOD1;
        hash2_[i] = (str[i] + (B * hash2_[i + 1]) % MOD2) % MOD2;
    }
}

// 0 based
pair<ll, ll> get_hash(int l, int r) {
    ll h1 = (hash1_[l] - (hash1_[r + 1] * pow_b1_[r - l + 1]) % MOD1) % MOD1;
    ll h2 = (hash2_[l] - (hash2_[r + 1] * pow_b2_[r - l + 1]) % MOD2) % MOD2;
    if (h1 < 0) h1 += MOD1;
    if (h2 < 0) h2 += MOD2;
    return mp(h1, h2);
}
