def dfs(v):
	mark[v] = True
	for u in g[v]:
		if mark[u] == False:
			dfs(u)

tc = 1
while True:
	n, m = map(int, raw_input().split())
	if n == 0: break
	
	g = [[] for i in range(n)]
	for i in range(m):
		u, v = map(int, raw_input().split())
		u, v = u - 1, v - 1
		g[u].append(v)
		g[v].append(u)
	
	mark = [False]*n
	dfs(0)
	
	fail = False
	for i in range(n):
		if mark[i] == False:
			fail = True
			break
	print "Teste " + str(tc)
	if fail: print "falha\n"
	else: print "normal\n"
	
	tc = tc + 1
