import sys

m = {}

total = 0
for s in sys.stdin.readlines():
    s = s.rstrip()

    if s not in m:
        m[s] = 0
    m[s] += 1
    total += 1

for e in sorted(m.items()):
    print("{} {:.4f}".format(e[0], 100 * e[1] / total))
