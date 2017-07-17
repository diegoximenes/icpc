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

class Trainer {
public:
    int d, t, s;
    Trainer() {}
    Trainer(int _d, int _t, int _s) : d(_d), t(_t), s(_s) {}
    bool operator<(const Trainer &o) const {
        return s < o.s;
    }
};

bool cmp(Trainer t1, Trainer t2) {
    return t1.d < t2.d;
}

#define MAX 100005

Trainer trainers[MAX];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        for (int i = 0; i < n; ++i)
            cin >> trainers[i].d >> trainers[i].t >> trainers[i].s;

        sort(trainers, trainers + n, cmp);
        priority_queue<Trainer> heap;
        int i_trainers = 0;
        for (int curr_d = 1; curr_d <= d; ++curr_d) {
            while (i_trainers < n && trainers[i_trainers].d <= curr_d)
                heap.push(trainers[i_trainers++]);

            if (!heap.empty()) {
                Trainer trainer = heap.top();
                heap.pop();
                if (trainer.t > 1)
                    heap.push(Trainer(trainer.d, trainer.t - 1, trainer.s));
            }
        }

        for (; i_trainers < n; i_trainers++) heap.push(trainers[i_trainers]);

        ll sol = 0;
        while (!heap.empty()) {
            sol += 1LL * heap.top().t * heap.top().s;
            heap.pop();
        }
        cout << sol << endl;
    }

    return 0;
}
