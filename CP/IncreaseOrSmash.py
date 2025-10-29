t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    
    ops = 0
    prev = 0  # baseline after previous operations
    for x in a:
        if x > prev:
            ops += x - prev  # Increase to reach current element
        # if x <= prev, no new increase is needed; Smash is absorbed
        prev = x  # update baseline
    
    print(ops)
