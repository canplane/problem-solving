N = int(input())

def check(s):
    bias = 0
    for c in s:
        if c == "(":
            bias += 1
        elif c == ")":
            if bias == 0:
                return False
            bias -= 1
    return bias == 0   

for _ in range(N):
    s = input()
    print("YES" if check(s) else "NO")