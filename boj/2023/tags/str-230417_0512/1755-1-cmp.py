d = [ "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" ]

#### like strcmp
from functools import cmp_to_key
def _cmp(a, b):
    a, b = str(a), str(b)
    for i in range(min(len(a), len(b))):
        if a[i] != b[i]:
            return -1 if d[int(a[i])] < d[int(b[i])] else 1
    return len(a) - len(b)
####

M, N = map(int, input().split())

li = []
for i in range(M, N + 1):
    li.append(i)
li.sort(key=cmp_to_key(_cmp))   ####

for i in range(len(li)):
    print(li[i], end=" ")
    if i % 10 == 9:
        print()