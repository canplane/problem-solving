try:
    while True:
        a = sum(map(int, input().split()))
        if not a:   raise Exception
        print(a)
except:
    pass