def minJumpsRec(arr, startIndex, endIndex):
    # Base Cases
    if startIndex == endIndex:
        return 0
    if arr[startIndex] == 0:
        return float('inf')

    # Now traverse through all the points reachable from arr[startIndex].
    # Recursively get the minimum number of jumps needed to reach arr[endIndex]
    # from these reachable points.
    minJs = float('inf')
    for i in range(startIndex+1, endIndex+1):
        if (i < startIndex + arr[startIndex] + 1):
            jumps = minJumpsRec(arr, i, endIndex)
            if (jumps + 1 < minJs):
                minJs = jumps + 1
    return minJs

# def minJ(arr, s, e):
#     for i in arr:
#         for k in range(1, i+1):
#             jumps = minJ(arr, s+k, e)
#             minjs = min(minjs, jumps+1)

n = int(input())
arr = [int(i) for i in input().split(' ')]
print(minJumpsRec(arr, 0, n))