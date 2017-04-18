#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define MAX 100005

struct Line {
    ll a, b;
    Line(ll _a = 0, ll _b = 0) : a(_a), b(_b) {}
};

Line convex_hull_[MAX];
int ptr_, len_;

bool irrelevant(Line l1, Line l2, Line l3) {
    double left = (double)(l3.b - l1.b) / (double)(l1.a - l3.a);
    double right = (double)(l2.b - l1.b) / (double)(l1.a - l2.a);
    return (left < right);
}

// consider that a[i] > a[i + 1] (slope),
// the overall complexity of adding all lines is O(n)
void add_line(Line l) {
    while ((len_ >= 2) &&
           irrelevant(convex_hull_[len_ - 2], convex_hull_[len_ - 1], l)) {
        --len_;
    }
    convex_hull_[len_++] = l;
}

// consider that queries are non-decreasing,
// the overall complexity of all queries is O(n).
// if is not non-decreasing use binary-search
ll query(ll x) {
    ptr_ = min(ptr_, len_ - 1);
    while ((ptr_ + 1 < len_) &&
           (convex_hull_[ptr_ + 1].a * x + convex_hull_[ptr_ + 1].b <=
            convex_hull_[ptr_].a * x + convex_hull_[ptr_].b)) {
        ++ptr_;
    }
    return convex_hull_[ptr_].a * x + convex_hull_[ptr_].b;
}

void init() {
    len_ = 0;
    ptr_ = 0;
}

ll a[MAX], b[MAX];

int main() {
    int n;

    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    init();
    ll sol = 0;
    for (int i = 0; i < n; ++i) {
        if (i != 0) sol = query(a[i]);
        add_line(Line(b[i], sol));
    }

    cout << sol << endl;

    return 0;
}
