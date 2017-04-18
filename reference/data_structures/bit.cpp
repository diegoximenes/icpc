/*
first indice of BIT is 1
*/

#include <bits/stdc++.h>
using namespace std;

#define MAX 100

int tree_[MAX], n_;

// O(logn)
inline int query(int idx) {
    int sum = 0;
    while (idx > 0) {
        sum += tree_[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

// O(logn)
inline int query(int a, int b) {
    return query(b) - query(a - 1);
}

// O(logn)
inline void update(int idx, int val) {
    while (idx <= n_) {
        tree_[idx] += val;
        idx += (idx & -idx);
    }
}

// O(n)
inline void scale(int c) {
    for (int i = 1; i <= n_; i++)
        tree_[i] = tree_[i] * c;
}

void init(int n) {
    n_ = n;
    memset(tree_, 0, sizeof(tree_));
}

int main()
{
    init(8);
    update(2, 1);
    update(4, 1);
    update(5, 2);
    update(6, 3);
    update(7, 2);
    update(8, 1);
    //BIT = [0, 0, 1, 0, 1, 2, 3, 2, 1]
    printf("%d\n", query(6)); //7
    printf("%d\n", query(1,1)); //0
    printf("%d\n", query(1,2)); //1
    printf("%d\n", query(1,6)); //7
    printf("%d\n", query(1,8)); //10
    printf("%d\n", query(3,6)); //6
    scale(2);
    //BIT = [0, 0, 2, 0, 2, 4, 6, 4, 2]
    printf("%d\n", query(6)); //14
    printf("%d\n", query(1,1)); //0
    printf("%d\n", query(1,2)); //2
    printf("%d\n", query(1,6)); //14
    printf("%d\n", query(1,8)); //20
    printf("%d\n", query(3,6)); //12
    return 0;
}
