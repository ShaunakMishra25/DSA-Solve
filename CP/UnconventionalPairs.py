t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    min_max_diff = a[n//2] - a[n//2 - 1]
    print(min_max_diff)