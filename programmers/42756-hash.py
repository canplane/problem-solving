# 완주하지 못한 선수: https://school.programmers.co.kr/learn/courses/30/lessons/42576

dic = {}

def solution(participant, completion):
	for name in participant:
		if name not in dic:
			dic[name] = 0
		dic[name] += 1
	for name in completion:
		dic[name] -= 1
	
	for name in dic:
		if dic[name] > 0:
			return name