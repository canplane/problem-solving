def is_palindrom(s):
    t = s[::-1]
    return t == s


T = int(input())
for _ in range(T):
    k = int(input())
    A = [input() for _ in range(k)]
    
    s = 0
    try:
        for i in range(k):
            for j in range(k):
                if i == j:
                    continue
                s_temp = A[i] + A[j]
                if is_palindrom(s_temp):
                    s = s_temp
                    raise KeyError
    except:
        pass
    print(s)
