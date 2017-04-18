inline int next_int() {
    int n = 0;
    char c = getchar_unlocked();
    while (!('0' <= c && c <= '9')) c = getchar_unlocked();
    while ('0' <= c && c <= '9') {
        n = n * 10 + c - '0';
        c = getchar_unlocked();
    }
    return n;
}
