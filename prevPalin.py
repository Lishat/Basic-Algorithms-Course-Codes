import re
def sub(g, f):
	borrow = 0
	q = -1
	m = -len(g)
	while q >= m:
		if(q == -1):
			r = ord(g[q]) + f
		else:
			r = ord(g[q]) + borrow
			borrow = 0
		if r >= 58:
			borrow = 1
			r -= 10
		g[q] = chr(r)
		if(borrow == 0):
			break
		q -= 1
	if borrow == 1:
		List = ["1"]
		List.extend(g)
		return List
	else:
		return g
for _ in range(int(input())):
	a = input()
	c = len(a)
	e = (c-1)//2
	if(bool(re.match(r'^([1]+[0]*[1]+)$', a)) == True):
		print(*sub(list(a), 2), sep="")
	else:
		a = list(a)
		d = a
		if(c%2 ==1):
			b = a[:e] + a[e::-1]
		else:
			b = a[:e+1] + a[e::-1]
		while(d >= b):
			if(c%2 ==1):
				a = sub(a[:e+1], 1)
				a += a[-2::-1]
				b = a
			else:
				a = sub(a[:e+1], 1)
				a += a[::-1]
				b = a
		print(*b,sep="") 