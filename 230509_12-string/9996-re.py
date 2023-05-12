import sys
input = lambda: sys.stdin.readline().rstrip()

N = int(input())
import re
pattern = re.compile(input().replace("*", ".*"))
for _ in range(N):
    s = input()
    r = re.search(pattern, s)
    print("DA" if (r and r.group() == s) else "NE")