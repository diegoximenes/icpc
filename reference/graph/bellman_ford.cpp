// version1
for (int i = 0; i < n; ++i) dist[i][0] = INF;
dist[s][0] = 0;
for (int i = 1; i < n; ++i)
    for (int v = 0; v < n; ++v) {
        dist[v][i] = dist[v][i-1];
        for (int j = 0; j < (int) g[v].size(); ++j)
            dist[v][i] = min(dist[v][i],
                             dist[g[v][j].first][i - 1] + g[v][j].second);
    }


// version2
for (int i = 0; i < n; ++i) dist[i] = INF;
dist[s] = 0;
for (int i = 0; i < n - 1; ++i)
    for (int v = 0; v < n; ++v)
        for (int j = 0; j < (int) g[v].size(); ++j)
            dist[v] = min(dist[v], dist[g[v][j].first] + g[v][j].second);

