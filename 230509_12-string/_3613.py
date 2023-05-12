# 조건 분기를 잘 해야할 듯 하다.

s = input()
t = ""

is_err, is_c, is_java = [None] * 3

i = 0
while i < len(s):
    if s[i].islower():
        t += s[i]
    else:
        if i > 0 and s[i].isupper():
            is_java = True
            t += "_" + s[i].lower()
        elif i > 0 and s[i] == "_" and ((i := i + 1) < len(s) and s[i].islower()):
            is_c = True
            t += s[i].upper()
        else:
            is_err = True
    i += 1

if is_c and is_java:
    is_err = True
print("Error!" if is_err else t)