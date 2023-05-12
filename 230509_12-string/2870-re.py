import re

M = int(input())
li = []
for _ in range(M):
	li += re.findall(r"\d+", input())
li = [int(e) for e in li]
li.sort()
for e in li:
	print(e)