import sys
input = lambda: sys.stdin.readline().rstrip()
####

s = input()
li = []
for i in range(len(s)):
	li.append(s[i:])
li.sort()
for e in li:
	print(e)