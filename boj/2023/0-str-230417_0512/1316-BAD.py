N = int(input())

ret = 0
for _ in range(N):
    inc = 1

    visit = set()
    prev = -1
    for c in input():
        if c == prev:   continue
        prev = c

        if c in visit:
            inc = 0
            break
        visit.add(c)
    
    ret += inc

print(ret)