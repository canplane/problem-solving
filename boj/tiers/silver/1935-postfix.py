N = int(input())
A = input()
x = []
while True:
	try:
		x.append(int(input()))
	except:
		break

st = []
for i in range(len(A)):
	if A[i] == '+':
		b, a = st.pop(), st.pop()
		st.append(a + b)
	elif A[i] == '-':
		b, a = st.pop(), st.pop()
		st.append(a - b)
	elif A[i] == '*':
		b, a = st.pop(), st.pop()
		st.append(a * b)
	elif A[i] == '/':
		b, a = st.pop(), st.pop()
		st.append(a / b)
	else:
		st.append(x[ord(A[i]) - 65])
print(f"{st[-1]:.2f}")