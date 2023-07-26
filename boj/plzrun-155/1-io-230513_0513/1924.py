D = ( 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 )
S = ( "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" )
m, d = map(int, input().split())
for e in D[:m]:	d += e
print(S[d % 7])