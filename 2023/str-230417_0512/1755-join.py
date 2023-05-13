d = [ "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" ]

M, N = map(int, input().split())

li = []
for i in range(M, N + 1):
    s = " ".join([ d[int(c)] for c in str(i) ])
    li.append([s, i])
li.sort()   # li.sort(lambda x: x[0])

for i in range(len(li)):
    print(li[i][1], end=" ")
    if i % 10 == 9:
        print()