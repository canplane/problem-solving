TOKENS = [ "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" ]

s = input()

cnt = 0
pos = 0
while pos < len(s):
    is_one = True
    for t in TOKENS:
        pos_t = s.find(t, pos)
        if pos_t == pos:
            is_one = False
            pos += len(t)
            break
    if is_one == True:
        pos += 1
    cnt += 1

print(cnt)