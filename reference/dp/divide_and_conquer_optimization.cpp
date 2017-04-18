#include <bits/stdc++.h>
using namespace std;

#define NMAX 4005
#define KMAX 805
#define INF 0x3f3f3f3f

int dp[KMAX][NMAX], best_k[KMAX][NMAX];

int u[NMAX][NMAX];
int cost[NMAX][NMAX], sum_row[NMAX][NMAX];

void compute(int i, int left, int right, int best_k_left, int best_k_right) {
    if (right < left) return;
    int mid = (left + right) / 2;

    dp[i][mid] = INF;
    for (int k = best_k_left; k <= min(best_k_right, mid); ++k)
        if (cost[k][mid] + dp[i - 1][k - 1] < dp[i][mid]) {
            dp[i][mid] = cost[k][mid] + dp[i - 1][k - 1];
            best_k[i][mid] = k;
        }

    if(left != right) {
        compute(i, left, mid - 1, best_k_left, best_k[i][mid]);
        compute(i, mid + 1, right, best_k[i][mid], best_k_right);
    }
}

int main() {
    ios::sync_with_stdio(false);

    int n, k;

    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> u[i][j];

    for (int i = 1; i <= n; ++i) {
        sum_row[i][i] = 0;
        for (int j = i + 1; j <= n; ++j)
            sum_row[i][j] = u[i][j] + sum_row[i][j - 1];
    }
    cost[n][n] = u[n][n];
    for (int i = n - 1; i >= 1; --i)
        for (int j = i + 1; j <= n; ++j)
            cost[i][j] = sum_row[i][j] + cost[i + 1][j];

    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) dp[0][i] = INF;
    for (int i = 1; i <= k; ++i) compute(i, 1, n, 1, n);

    cout << dp[k][n] << endl;

    return 0;
}

/*
http://codeforces.com/problemset/problem/321/E

Statement:
Fox Ciel is in the Amusement Park. And now she is in a queue in front of the Ferris wheel. There are n people (or foxes more precisely) in the queue: we use first people to refer one at the head of the queue, and n-th people to refer the last one in the queue.

There will be k gondolas, and the way we allocate gondolas looks like this:

When the first gondolas come, the q1 people in head of the queue go into the gondolas.
Then when the second gondolas come, the q2 people in head of the remain queue go into the gondolas.
    ...

The remain qk people go into the last (k-th) gondolas.
Note that q1, q2, ..., qk must be positive. You can get from the statement that  and qi > 0.

You know, people don't want to stay with strangers in the gondolas, so your task is to find an optimal allocation way (that is find an optimal sequence q) to make people happy. For every pair of people i and j, there exists a value uij denotes a level of unfamiliar. You can assume uij = uji for all i, j (1 ≤ i, j ≤ n) and uii = 0 for all i (1 ≤ i ≤ n). Then an unfamiliar value of a gondolas is the sum of the levels of unfamiliar between any pair of people that is into the gondolas.

A total unfamiliar value is the sum of unfamiliar values for all gondolas. Help Fox Ciel to find the minimal possible total unfamiliar value for some optimal allocation.

Input
The first line contains two integers n and k (1 ≤ n ≤ 4000 and 1 ≤ k ≤ min(n, 800)) — the number of people in the queue and the number of gondolas. Each of the following n lines contains n integers — matrix u, (0 ≤ uij ≤ 9, uij = uji and uii = 0).

Please, use fast input methods (for example, please use BufferedReader instead of Scanner for Java).

Output
Print an integer — the minimal possible total unfamiliar value.

Solution:

This problem may jog your memory of OI times (if you have been an OIer and now grows up, like me). Maybe some Chinese contestants might think this problem doesn't worth 2500, but DP optimization is an advanced topic in programming contest for many regions. It's quite easy to find an O(N^2 K) DP:

dp[i][j] = max{ k | dp[i-1][k] + cost(k+1...j)}
(dp[i][j] means the minimal cost if we divide 1...j foxes into i groups)

There are many ways to optimize this kind of dp equation, but a large part of them based one the property of cost function. So we need to find some property independent of cost function.

Let opt[i][j] = the smallest k such that dp[i][j] = dp[i][k] + cost(k+1...j) Then intuitively we have opt[i][1] <= opt[i][2] <= ... <= opt[i][n]. (I admit some people don't think it's intuitively correct, but it can proof by some high school algebra)

Then how to use this stuff?

Let n = 200 and suppose we already get dp[i][j] for i<=3 and now we have to compute dp[4][j]: If we first compute dp[4][100], then we can have opt[4][100] at the same time.

And when we compute dp[4][1] ... dp[4][99], we know that the k must lay in 1...opt[4][100]. When we compute dp[4][101] ... dp[4][200], we know that k must lay in opt[4][100]...n.

Let's formalize this thing: We use compute(d, L, R, optL, optR) to denote we are computing dp[d][L...R], and we know the k must be in range optL...optR.

Then we have:

compute(d, L, R, optL, optR) =

    1. special case: L==R.

    2. let M = (L+R) / 2, we solve dp[d][M] as well as opt[d][M]. Uses about (optR-optL+1) operations.

    3. compute(d, L, M-1, optL, opt[d][M])

    4. compute(d, M+1, R, opt[d][M], optR)
One can show that this solution will run in O(NlogN * K). Note that we don't need opt[d][M] at the center of interval optL...optR. We can proof at each recursive depth, the total cost by line 2 will be no more than 2n. And there are at most O(log(n)) depths.
*/
