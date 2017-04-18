int cnt_sets_, set_[MAX], size_[MAX];

void init(int n) {
    for (int i = 0; i < n; ++i) {
        set_[i] = i;
        size_[i] = 1;
    }
    cnt_sets_ = n;
}

int find_set(int i) {
    return (set_[i] == i) ? i : (set_[i] = find_set(set_[i]));
}

bool is_same_set(int i, int j) {
    return (find_set(i) == find_set(j));
}

void union_set(int i, int j) {
    if (is_same_set(i, j)) return;
    size_[find_set(j)] += size_[find_set(i)];
    set_[find_set(i)] = find_set(j);
    --cnt_sets_;
}
