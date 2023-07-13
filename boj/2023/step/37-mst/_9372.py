# 정직하게 짜면 함정. 정직하게 짜도 트리. mst 알고리즘 ㄴㄴ

import sys
input = lambda: sys.stdin.readline().rstrip()

T = int(input())
for _ in range(T):
    N, M = map(int, input().split())
    for _ in range(M):
        input()
    print(N - 1)