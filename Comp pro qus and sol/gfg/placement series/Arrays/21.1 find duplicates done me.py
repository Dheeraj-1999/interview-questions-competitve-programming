def duplicates(arr, n): 
    d = {}
    l = []
    for i in arr:
        d[i] = 0
    for i in arr:
        d[i] += 1
    for i in range(n):
        if(d[arr[i]] > 1):
            l.append(arr[i])
            d[arr[i]] = 1
    if(len(l) == 0):
        l.append(-1)
    return sorted(l)