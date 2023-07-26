A, B, C = map(int, input().split())

if A <= B:
	if B <= C:
		print(B)	# ABC
	else:
		if A <= C:
			print(C)	# ACB
		else:
			print(A)	# CAB
else:
	if A <= C:
		print(A)	# BAC
	else:
		if B <= C:
			print(C)	# BCA
		else:
			print(B)	# CBA