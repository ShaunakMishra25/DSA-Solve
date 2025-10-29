t = int(input())
for _ in range(t):
    n = int(input())
    a= list(map(int, input().split()))
    a.sort()
    zeros = a.count(0)
    negs = a.count(-1)
    
    ops = zeros  

    if negs % 2 == 1 :
        ops += 2

    print(ops)
 