def sndMax(arr):
    Max, sMax = float('-inf'), float('-inf')
    n = len(arr)
    for i in range (n):
        if arr[i] > Max:
            sMax=Max
            Max= arr[i]
        elif (arr[i]> sMax and arr[i]!= Max):
            sMax = arr[i]
            
    return sMax if sMax != float('-inf') else None