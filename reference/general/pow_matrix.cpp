#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MAX 110

typedef ll mat_type;

struct Mat {
    int n;
    mat_type m[MAX][MAX];

    Mat(int _n = 0) : n(_n) {}
    Mat operator*(const Mat &o) const {
        Mat ret;
        int n = ret.n = o.n;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                ret.m[i][j] = 0;
                for (int k = 0; k < n; ++k)
                    ret.m[i][j] = ret.m[i][j] + m[i][k] * o.m[k][j];
            }
        return ret;
    }
};

Mat pow_matrix(Mat base, ll e) {
    Mat ret(base.n);
    int n = base.n;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            ret.m[i][j] = (i == j);
    while (e) {
        if (e & 1) ret = ret * base;
        e >>= 1;
        base = base * base;
    }
    return ret;
}
