li = list(map(int, input().split()))

prev = li[0]
asc, dsc = False, False
for d in li[1:]:
    if prev < d:
        asc = True
    else:
        dsc = True
    prev = d

if asc and dsc:
    print("mixed")
elif asc:
    print("ascending")
else:
    print("descending")