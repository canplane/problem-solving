s = input()

stack = []

cnt = 0
for c in s:
    if c == "(":
        stack.append(c)
    elif c == ")":
        if len(stack) > 0 :
            stack.pop()
        else:
            cnt += 1
cnt += len(stack)

print(cnt)