s = input()

res = ""

stack = []
i = 0
while i < len(s):
    if s[i].isdigit() or s[i].isalpha():
        stack.append(s[i])
    else:
        while len(stack) > 0:   res += stack.pop()
        if s[i] == "<":
            r = s.find(">", i + 1)
            res += s[i:(r + 1)]
            i = r
        else:
            res += s[i]
    i += 1
while len(stack) > 0:   res += stack.pop()

print(res)