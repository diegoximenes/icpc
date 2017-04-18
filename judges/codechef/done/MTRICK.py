import sys

t = int(raw_input())
for tc in range(t):
	n = int(raw_input())
	
	l = []
	lout = []
	s = raw_input().split()
	for i in range(n): l.append(long(s[i])) 
	
	s = raw_input().split()
	a, b, c = long(s[0]), long(s[1]), long(s[2])

	pl = 0
	pr = n - 1
	pleft = True
	cum = 0
	mul = 1
	s = raw_input()
	for i in range(n):
		if s[i] == 'A': 
			cum = (cum + a)%c
			if pleft:
				lout.append((l[pl]*mul + cum)%c)
				pl = pl + 1
			else:
				lout.append((l[pr]*mul + cum)%c)
				pr = pr - 1
		elif s[i] == 'M': 
			mul = (mul*b)%c
			cum = (cum*b)%c
			if pleft:
				lout.append((l[pl]*mul + cum)%c)
				pl = pl + 1
			else:
				lout.append((l[pr]*mul + cum)%c)
				pr = pr - 1
		else:
			if pleft: 
				lout.append((l[pr]*mul + cum)%c)
				pr = pr - 1
				pleft = False
			else: 
				lout.append((l[pl]*mul + cum)%c)
				pl = pl + 1
				pleft = True
			
	sys.stdout.write(str(lout[0]))
	for i in range(1, n): sys.stdout.write(' ' + str(lout[i]))
	print ""
