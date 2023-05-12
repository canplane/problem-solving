S = input()
A = [ input() for _ in range(int(input())) ]

def recur(pos):
    if pos == len(S):
        return True
    for a in A:
        if S.startswith(a, pos) and recur(pos + len(a)):
            return True
    return False

print(int(recur(0)))