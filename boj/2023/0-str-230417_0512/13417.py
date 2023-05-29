import sys
lines = sys.stdin.readlines()

i = 2
while i < len(lines):
    res = ""
    for c in lines[i].rstrip().split(" "):
        res = min(res + c, c + res)
    print(res)
    i += 2