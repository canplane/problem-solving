# 메모리가 제한!

import sys
input = lambda: sys.stdin.readline().rstrip()

N = int(input())
A = [ int(input()) for _ in range(N) ]
A.sort()
for a in A:
    print(a)


# 8 MB면 2^23 B = (4 B) * 2^21. 즉 4 B로 잡아도 2097152개 저장하는 게 최대.
# 근데 N 최대 10000000개므로 메모리 초과 나는 게 당연
# -> 비교 정렬이 아닌 정렬로 가야 함 -> 계수 정렬