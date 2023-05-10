s = input()
p = input()

li = []
pos = -1
while True:
    pos = s.find(p, pos + 1)
    if pos == -1:
        break
    li.append(pos)

cnt = 0     #
pos = -1    #
for i in range(len(li)):
    if pos == -1 or li[i] >= pos + len(p):
        pos = li[i]
        cnt += 1
print(cnt)