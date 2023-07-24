# 오픈채팅방: https://school.programmers.co.kr/learn/courses/30/lessons/42888

nickname = {}
log = []

def solution(record):
    for s in record:
        li = s.split()
        if li[0] == "Enter":
            nickname[li[1]] = li[2]
            log.append([li[1], True])
        elif li[0] == "Change":
            nickname[li[1]] = li[2]
        else:
            log.append([li[1], False])
    
    ans = []
    for id, enter in log:
        ans.append(f"{nickname[id]}님이 {'들어왔' if enter else '나갔'}습니다.")
    return ans