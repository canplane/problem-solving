f = [0] * 21
f[0] = 0; f[1] = 1 
for i in range(2, 21):
    f[i] = f[i - 1] + f[i - 2]

print(f[int(input())])