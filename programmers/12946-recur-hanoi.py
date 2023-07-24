# 하노이의 탑: https://school.programmers.co.kr/learn/courses/30/lessons/12946

ans = []
def recur(n, src, dst, tmp):
    if n == 0:
        return
    recur(n - 1, src, tmp, dst)
    ans.append([src, dst])
    recur(n - 1, tmp, dst, src)

def solution(n):
    recur(n, 1, 3, 2)
    return ans