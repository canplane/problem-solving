s = input()

patterns = [ "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" ]
for pattern in patterns:
    s = s.replace(pattern, " ")
print(len(s))