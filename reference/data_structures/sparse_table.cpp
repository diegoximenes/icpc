#include <bits/stdc++.h>
using namespace std;

template <class T>
class RMQSparseTable {
  private:
    vector<int> log2;
    vector<vector<T>> min_sparse_table;
    vector<vector<T>> max_sparse_table;

  public:
    RMQSparseTable(vector<T> &v) {
        int n = v.size();

        log2 = vector<int>(n + 1);
        log2[1] = 0;
        for (int i = 2; i <= n; ++i) {
            log2[i] = log2[i / 2] + 1;
        }

        min_sparse_table = vector<vector<T>>(n, vector<T>(log2[n] + 1));
        max_sparse_table = vector<vector<T>>(n, vector<T>(log2[n] + 1));
        for (int i = 0; i < n; ++i) {
            min_sparse_table[i][0] = v[i];
            max_sparse_table[i][0] = v[i];
        }
        for (int j = 1; j <= log2[n]; ++j) {
            for (int i = 0; i + (1 << j) <= n; ++i) {
                min_sparse_table[i][j] = std::min(
                    min_sparse_table[i][j - 1],
                    min_sparse_table[i + (1 << (j - 1))][j - 1]
                );
                max_sparse_table[i][j] = std::max(
                    max_sparse_table[i][j - 1],
                    max_sparse_table[i + (1 << (j - 1))][j - 1]
                );
            }
        }
    }

    T min(int l, int r) {
        int j = log2[r - l];
        return std::min(
            min_sparse_table[l][j], min_sparse_table[r - (1 << j) + 1][j]
        );
    }

    T max(int l, int r) {
        int j = log2[r - l];
        return std::max(
            max_sparse_table[l][j], max_sparse_table[r - (1 << j) + 1][j]
        );
    }
};
