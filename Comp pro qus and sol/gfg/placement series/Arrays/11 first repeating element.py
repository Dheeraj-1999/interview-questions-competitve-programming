def firstRepeated(arr, n):
    d = {}
    for i in arr:
        d[i] = 0
    for i in range(n):
        d[arr[i]] += 1
    maxi = -1
    index = 0
    for i in range(n):
        print(d[arr[i]] , maxi)
        if(d[arr[i]] > maxi):
            index = i
            maxi = d[arr[i]]
    return index

arr = [int(i) for i in input().split(' ')]
firstRepeated(arr, len(arr))