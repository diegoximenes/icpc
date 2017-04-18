from collections import deque

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

	#bfs
	s = 0
	mark = [False]*n
	q = deque([s])
	mark[s] = True
	while len(q) > 0:
		v = q.popleft()
		for u in g[v]:
			if mark[u] == False:
				mark[u] = True
				q.append(u)
	
	fail = False
	for i in range(n):
		if mark[i] == False:
			fail = True
			break
	print "Teste " + str(tc)
	if fail: print "falha\n"
	else: print "normal\n"
	
	tc = tc + 1
