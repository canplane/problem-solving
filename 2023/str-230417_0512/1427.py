import sys

a = sys.stdin.readline().rstrip()
b = sorted(a, reverse=True)
b = "".join(b)
print(b)