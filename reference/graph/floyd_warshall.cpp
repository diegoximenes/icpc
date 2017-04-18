for (int i = 1; i <= n; ++i)
    for(int j = 1; j <= n; ++j) {
        if (i == j)
            dist[i][i][0] = 0;
        else
            dist[i][j][0] = INF;
    }

for (int i = 0; i < m; ++i) {
    scanf("%d %d %d", &u, &v, &w);
    dist[u][v][0] = w;
}

for (int k = 1; k <= n; ++k)
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            dist[i][j][k] = min(dist[i][j][k - 1],
                                dist[i][k][k - 1] + dist[k][j][k - 1]);
